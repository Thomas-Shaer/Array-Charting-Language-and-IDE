#include "inputseries.h"
#include <fstream>
#include <sstream>
#include <algorithm> 
#include <string>
#include <boost/regex.hpp>
#include "dataparseexception.h"
#include "typesymbol.h"
#include "varsymbol.h"
#include "symboltable.h"
#include "outputwindow.h"
#include "datamanagerwindow.h"
#include "jsonsettings.h"



//https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c

std::pair<std::vector<ExpressionValue>, TypeSymbol*> InputSeries::parse(std::vector<std::string> rawValues, const std::string& TrueString, const std::string& FalseString, const std::string& NullString) {
    // type of series
    TypeSymbol* seriesType = nullptr;
    // list because we can add to back and front
    std::list<ExpressionValue> values;
    // the null type (float or boolean) to be determined
    ExpressionValue nullValue;
    // count of Nulls found before seriesType is determined
    unsigned int leadingNulls = 0;


    for (const std::string& cell : rawValues) {
        TypeSymbol* celltype = nullptr;
        /*
        Record Null value.
        If type not determined yet, just increase count of leading Nulls.
        */
        if (cell == NullString) {
            if (!seriesType) {
                leadingNulls++;
                continue;
            }
            values.push_back(nullValue);
        }
        /*
        Record boolean.
        */
        else if (cell == FalseString || cell == TrueString) {
            celltype = TypeInstances::GetBooleanInstance();
            values.push_back(NullableValueBoolean(cell == TrueString));
        }
        /*
        Record float
        */
        else if (boost::regex_match(cell, boost::regex("-?[0-9]+([\.][0-9]+)?"))) {
            celltype = TypeInstances::GetNumberInstance();
            values.push_back(NullableValueNumber(std::stof(cell)));
        }
        /*
        Any other we can't recognise is a error.
        */
        else {
            throw DataParseException("Unrecognised type: " + cell);
        }
        if (celltype) {
            /*
            The fist cell type will be the type of the series.
            */
            if (!seriesType) {
                seriesType = celltype;
                nullValue = seriesType == TypeInstances::GetBooleanInstance() ? ExpressionValue(NullableValueBoolean()) : ExpressionValue(NullableValueNumber());
            }
            /*
            If the current cells type is not the same as the first seen type, throw a error.
            */
            if (celltype != seriesType) {
                throw DataParseException("Initally found series to be : " + seriesType->name + " but " + celltype->name + " type found at line: " + cell);
            }
        }

    }

    /*
    If no values recorded therefore it is a empty series of data
    */
    if (values.empty()) {
        throw DataParseException("No data in series.");
    }

    /*
    Type not determined meaning it only contains Null values.
    */
    if (!seriesType) {
        throw DataParseException("Type could not be determined from series.");
    }
    /*
    Add leading Nulls now that we know the type.
    */
    for (int i = 0; i < leadingNulls; i++) {
        values.push_front(nullValue);
    }

    return { std::vector<ExpressionValue>(values.begin(), values.end()), seriesType };
}


std::string InputSeries::ImportPolicyToString(const ImportPolicy ip) {
    return ip == ImportPolicy::COLUMN_WISE ? "column-wise" : "row-wise";
}

ImportPolicy InputSeries::StringToImportPolicy(const std::string& name) {
    return name == "column-wise" ? ImportPolicy::COLUMN_WISE : ImportPolicy::ROW_WISE;
}

void InputSeries::LoadInputData(const ImportPolicy importPolicy, std::string name, std::string filename, const std::string& TrueString, const std::string& FalseString, const std::string& NullString) {
    

    /*
       If detected that the data file associated with the variable has been removed,
       attempt to load it in again.
       */
    for (auto shared_data : DataManagerWindow::LOADED_IN_DATA) {
        if (shared_data->path == name) {
            return;
        }
    }

    /*
    Row wise parsing of data.
    */
    std::vector<std::shared_ptr<InputSeries>> series;
    if (importPolicy == ImportPolicy::ROW_WISE) {
        std::ifstream fin(name);
        for (std::string line; std::getline(fin, line); ) {
            std::string firstWord = line.substr(0, line.find(","));
            std::istringstream in(line);
            std::getline(in, firstWord, ',');

            std::vector<std::string> row_data;

            while (in.good()) {
                std::string substr;
                std::getline(in, substr, ',');
                row_data.push_back(substr);
            }
           
            std::pair<std::vector<ExpressionValue>, TypeSymbol*> parsedResults = parse(row_data, TrueString, FalseString, NullString);
            std::shared_ptr<InputSeries> newdata = std::make_shared<InputSeries>(firstWord, filename, name, TrueString, FalseString, NullString, parsedResults.first, parsedResults.second, ImportPolicy::ROW_WISE);


            series.push_back(newdata);
        }
    }
    /*
    Column wise parsing of data.
    */
    else {
        unsigned int row = 0;
        std::map<std::string, std::vector<std::string>> columnData;
        std::vector<std::string> indexToColumn;
        std::ifstream fin(name);
        for (std::string line; std::getline(fin, line); ) {
            std::istringstream in(line);
            std::vector<std::string> row_data;

            while (in.good()) {
                std::string substr;
                std::getline(in, substr, ',');
                row_data.push_back(substr);
            }
            
            for (int i = 0; i < row_data.size(); i ++) {
                std::string cell = row_data[i];
                // if first row then init the column vectors
                if (row == 0) {
                    indexToColumn.push_back(cell);
                    columnData[cell] = std::vector<std::string>();
                }
                // else insert data into the column
                else {
                    columnData[indexToColumn[i]].push_back(cell);
                }
            }
            
            row++;
        }
        // loop through all series and register them
        for (const auto& it : columnData) {
            std::pair<std::vector<ExpressionValue>, TypeSymbol*> parsedResults = parse(it.second, TrueString, FalseString, NullString);
            std::shared_ptr<InputSeries> newdata = std::make_shared<InputSeries>(it.first, filename, name, TrueString, FalseString, NullString, parsedResults.first, parsedResults.second, ImportPolicy::COLUMN_WISE);
            series.push_back(newdata);
        }

    }


    DataManagerWindow::LOADED_IN_DATA.insert(DataManagerWindow::LOADED_IN_DATA.end(), series.begin(), series.end());

}


void InputSeries::renameVariable(const std::string& cvariableName) {
    std::shared_ptr<VarSymbol> oldSymbol = SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable[variableName];
    SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable.erase(SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable.find(variableName));
    variableName = cvariableName;

    std::shared_ptr<VarSymbol> varSymbol = VarSymbol::createVarSymbol(variableName, TypeInstances::GetNumberInstance(), oldSymbol->getArrayValues());
    SymbolTable::GLOBAL_SYMBOL_TABLE->declareVariable(varSymbol);
    OutputWindow::UpdateVariablesTab();
}

void InputSeries::deleteVariable() {
    SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable.erase(SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable.find(variableName));
    isVariable = false;
    OutputWindow::UpdateVariablesTab();

}


void InputSeries::createNewVariable(const std::string& cvariableName) {
    isVariable = true;
    variableName = cvariableName;
    std::shared_ptr<VarSymbol> varSymbol = VarSymbol::createVarSymbol(variableName, TypeInstances::GetNumberInstance(), data);
    SymbolTable::GLOBAL_SYMBOL_TABLE->declareVariable(varSymbol);
    OutputWindow::UpdateVariablesTab();

}
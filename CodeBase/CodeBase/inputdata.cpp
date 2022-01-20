#include "inputdata.h"
#include <fstream>
#include <sstream>
#include <algorithm> 
#include <string>
#include <boost/regex.hpp>
#include "dataparseexception.h"
#include "typesymbol.h"
//https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c

/*
Returns a ExpressionValue vector and TypeSymbol given a vector of strings.
Will throw a DataParseException if the parsed strings are incompatible
*/
std::pair<std::vector<ExpressionValue>, TypeSymbol*> parse(std::vector<std::string> rawValues, const std::string& TrueString, const std::string& FalseString, const std::string& NANString) {
    // type of series
    TypeSymbol* seriesType = nullptr;
    // list because we can add to back and front
    std::list<ExpressionValue> values;
    // the nan type (float or boolean) to be determined
    ExpressionValue nanType;
    // count of NaNs found before seriesType is determined
    unsigned int leadingNaNs = 0;


    for (const std::string& cell : rawValues) {
        //std::cout << cell << std::endl;
        TypeSymbol* celltype = nullptr;
        /*
        Record NaN type.
        If type not determined yet, just increase count of leading NaNs.
        */
        if (cell == NANString) {
            if (!seriesType) {
                leadingNaNs++;
                continue;
            }
            values.push_back(nanType);
            //std::cout << "leading" << std::endl;

        }
        /*
        Record boolean.
        */
        else if (cell == FalseString || cell == TrueString) {
            celltype = TypeInstances::GetBooleanInstance();
            values.push_back(Boolean(cell == TrueString));
            //std::cout << "what" << std::endl;
        }
        /*
        Record float
        */
        else if (boost::regex_match(cell, boost::regex("-?[0-9]+([\.][0-9]+)?"))) {
            celltype = TypeInstances::GetFloatInstance();
            values.push_back(Float(std::stof(cell)));
            //std::cout << "what3" << std::endl;

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
                nanType = seriesType == TypeInstances::GetBooleanInstance() ? ExpressionValue(Boolean()) : ExpressionValue(Float());
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
    Type not determined meaning it only contains NaN values.
    */
    if (!seriesType) {
        throw DataParseException("Type could not be determined from series.");
    }
    /*
    Add leading NaNs now that we know the type.
    */
    for (int i = 0; i < leadingNaNs; i++) {
        values.push_front(nanType);
    }

    return { std::vector<ExpressionValue>(values.begin(), values.end()), seriesType };
}


std::vector<std::shared_ptr<InputData>> InputData::LoadInputData(const ImportPolicy importPolicy, std::string name, std::string filename, const std::string& TrueString, const std::string& FalseString, const std::string& NANString) {
    
    std::vector<std::shared_ptr<InputData>> series;
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
           
            std::pair<std::vector<ExpressionValue>, TypeSymbol*> parsedResults = parse(row_data, TrueString, FalseString, NANString);
            std::shared_ptr<InputData> newdata = std::make_shared<InputData>();
            
            newdata->name = firstWord;
            newdata->path = name;
            newdata->fileName = filename;
            newdata->type = parsedResults.second;
            newdata->data = parsedResults.first;
            newdata->importPolicy = ImportPolicy::ROW_WISE;
            newdata->trueLiteral = TrueString;
            newdata->falseLiteral = FalseString;
            newdata->nanLiteral = NANString;

            series.push_back(newdata);
        }
    }

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
            std::pair<std::vector<ExpressionValue>, TypeSymbol*> parsedResults = parse(it.second, TrueString, FalseString, NANString);
            std::shared_ptr<InputData> newdata = std::make_shared<InputData>();
            newdata->name = it.first;
            newdata->path = name;
            newdata->fileName = filename;
            newdata->type = parsedResults.second;
            newdata->data = parsedResults.first;
            newdata->importPolicy = ImportPolicy::COLUMN_WISE;
            newdata->trueLiteral = TrueString;
            newdata->falseLiteral = FalseString;
            newdata->nanLiteral = NANString;
            series.push_back(newdata);
        }

    }

    return series;

}

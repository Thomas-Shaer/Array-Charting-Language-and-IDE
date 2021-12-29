#include "exportdata.h"
#include <fstream>
#include "varsymbol.h"
#include "visitors.h"

void exportColumnWise(const std::string& filePath, std::vector<std::shared_ptr<VarSymbol>> variables) {
    std::ofstream myFile(filePath);


    for (int j = 0; j < variables.size(); ++j)
    {
        myFile << variables.at(j)->exportName;
        if (j != variables.size() - 1) myFile << ","; // No comma at end of line
    }
    myFile << "\n";


    for (int i = 0; i < variables.at(0)->buffer.size(); ++i)
    {
        for (int j = 0; j < variables.size(); ++j)
        {
            myFile << boost::apply_visitor(ToFileString(), variables.at(j)->buffer[i]);
            if (j != variables.size() - 1) myFile << ","; // No comma at end of line
        }
        myFile << "\n";
    }
    myFile.close();

}



void exportRowWise(const std::string& filePath, std::vector<std::shared_ptr<VarSymbol>> variables) {
    std::ofstream myFile(filePath);


    for (std::shared_ptr<VarSymbol> var : variables)
    {
        myFile << var->exportName << ",";
        for (int i = 0; i < var->buffer.size(); i ++) {
            myFile << boost::apply_visitor(ToFileString(), var->buffer[i]);
            if (i != var->buffer.size() - 1) myFile << ","; // No comma at end of line
        }
        myFile << "\n";

    }

    myFile.close();

}
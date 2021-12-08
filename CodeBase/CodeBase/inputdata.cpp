#include "inputdata.h"
#include <fstream>
#include <sstream>
#include <algorithm> 
#include <string>

std::vector<std::shared_ptr<InputData>> InputData::LoadInputData(std::string name, std::string filename) {

    std::vector<std::shared_ptr<InputData>> values;
    std::ifstream fin(name);

    for (std::string line; std::getline(fin, line); )
    {
        std::string firstWord = line.substr(0, line.find(","));
        line = line.substr(firstWord.size(), line.max_size());
        std::replace(line.begin(), line.end(), ',', ' ');
        std::istringstream in(line);
        
        std::shared_ptr<InputData> newdata = std::make_shared<InputData>();
        newdata->name = firstWord;
        newdata->data = std::vector<float>(std::istream_iterator<float>(in), std::istream_iterator<float>());
        newdata->fileName = filename;

        values.push_back(newdata);
    }

    return values;

}

#include "maingui.h"
#include "interpretercontext.h"
#include <nlohmann/json.hpp>
#include "jsonsettings.h"
#include <fstream>
#include <sstream>

void newJSON() {
    Settings::settingsFile["zoom"] = 1;
    Settings::settingsFile["windowwidth"] = 1800;
    Settings::settingsFile["windowheight"] = 800;
    Settings::settingsFile["lastDirectory"] = "";
    Settings::saveSettings();
}

int main(int, char**) {

   

    std::ifstream inputjson(SAVE_NAME);
    if (inputjson) {
        try {
            inputjson >> Settings::settingsFile;
        }
        catch (std::exception e) {
            newJSON();
        }
    }
    else {
        newJSON();
    }


	return start();

}
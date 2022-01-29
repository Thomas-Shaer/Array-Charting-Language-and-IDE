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
    Settings::settingsFile["lastDataImportDirectory"] = "";
    Settings::settingsFile["loadedInData"] = nlohmann::json::array();
    Settings::settingsFile["currentCodeFile"] = "";
    Settings::settingsFile["lastCodeSaveDirectory"] = "";
    Settings::settingsFile["lastDataExportDirectory"] = "";
    Settings::settingsFile["lastCodeOpenDirectory"] = "";
    Settings::settingsFile["defaultTrueImportLiteral"] = "TRUE";
    Settings::settingsFile["defaultFalseImportLiteral"] = "FALSE";
    Settings::settingsFile["defaultNANImportLiteral"] = "NAN";
    Settings::settingsFile["defaultTrueExportLiteral"] = "TRUE";
    Settings::settingsFile["defaultFalseExportLiteral"] = "FALSE";
    Settings::settingsFile["defaultNANExportLiteral"] = "NAN";
    Settings::settingsFile["lastScreenshotExportDirectory"] = "";
    Settings::settingsFile["chartAntiAliasing"] = true;
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
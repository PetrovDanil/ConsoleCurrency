#include "Helper.h"
#include <string>
#include <fstream>
#include <sstream>

std::string Helper::getEnv(const std::string& key) {
    const std::string fileName = ".env";
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string currentKey, value;
        if (std::getline(iss, currentKey, '=') && std::getline(iss, value)) {
            if (currentKey == key) {
                return value;
            }
        }
    }
    return "";
}

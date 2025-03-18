#include "Helper.h"
#include "Exceptions/EnvFileNotExist/EnvFileNotExist.h"
#include "Exceptions/EnvKeyNotExist/EnvKeyNotExist.h"
#include <string>
#include <fstream>
#include <sstream>

std::string Helper::getEnv(const std::string& key) {
    const std::string fileName = ".env";
    std::ifstream file(fileName);
    if (!file) {
        throw EnvFileNotExist();
    }
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
    throw EnvKeyNotExist();
}

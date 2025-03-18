#include "Logger.h"
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>

Logger* Logger::instance = nullptr;

Logger* Logger::getInstance() {
    if (instance == nullptr) {
        instance = new Logger();
    }
    return instance;
}

bool Logger::isLogFileExist() {
    return std::filesystem::exists(logFileName);
}

void Logger::createLogFile() {
    std::ofstream logFile(logFileName);
    logFile.close();
}

std::string Logger::getDateTime() {
    time_t timestamp;
    time(&timestamp);
	return ctime(&timestamp);
}

void Logger::writeLog(const char* logStr) {
    if (!isLogFileExist()) {
		createLogFile();
    }
    std::ofstream logFile(logFileName, std::ios_base::app);
    logFile << "Error: " << getDateTime() << " " << logStr << std::endl;
    logFile.close();
}


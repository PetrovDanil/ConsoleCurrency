#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger
{
public:
	void writeLog(const char* logStr);
	static Logger* getInstance();
private:
	static Logger* instance;
	Logger() = default;
	bool isLogFileExist();
	void createLogFile();
	std::string logFileName = "log.txt";
	std::string getDateTime();
};
#endif


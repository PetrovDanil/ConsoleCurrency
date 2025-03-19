// ConsoleCurrency.cpp: определяет точку входа для приложения.
//

#include "ConsoleCurrency.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	std::string apiKey;
	try
	{
		Helper::getEnv("API_CURRENCY_TOKEN");
	}
	catch (const std::exception& ex)
	{
		Logger* logger = Logger::getInstance();
		logger->writeLog(ex.what());
		cout << ex.what() << endl;
	}
	//cout << Helper::getEnv("API_CURRENCY_TOKEN");
	return 0;
}

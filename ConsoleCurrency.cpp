// ConsoleCurrency.cpp: определяет точку входа для приложения.
//

#include "ConsoleCurrency.h"

using namespace std;

int main()
{
	cout << Helper::getEnv("API_CURRENCY_TOKEN");
	return 0;
}

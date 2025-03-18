#ifndef ENVKEYNOTEXIST_H
#define ENVKEYNOTEXIST_H

#include <exception>

class EnvKeyNotExist : public std::exception {
public:
    const char* what() const noexcept override;
private:
    const char* message = "Не найден ключ API_CURRENCY_TOKEN в .env файле!";
};

#endif 
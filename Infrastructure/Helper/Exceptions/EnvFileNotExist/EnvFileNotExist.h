#ifndef ENVFILENOTEXIST_H
#define ENVFILENOTEXIST_H

#include <exception>

class EnvFileNotExist : public std::exception {
public:
    const char* what() const noexcept override;
private:
    const char* message = "Файл .env не найден!";
};

#endif 
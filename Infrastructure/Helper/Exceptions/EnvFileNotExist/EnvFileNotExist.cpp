#include "EnvFileNotExist.h"

const char* EnvFileNotExist::what() const noexcept {
	return message;
}
#include "EnvKeyNotExist.h"

const char* EnvKeyNotExist::what() const noexcept {
	return message;
}
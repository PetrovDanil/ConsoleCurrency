# CMakeList.txt: проект CMake для ConsoleCurrency; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("ConsoleCurrency")

# Boost libs
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(Boost_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-windows/include")
set(Boost_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-windows/lib")
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# Добавьте источник в исполняемый файл этого проекта.
add_executable (
	ConsoleCurrency
	"ConsoleCurrency.cpp"
	"ConsoleCurrency.h"
	"Infrastructure/Helper/Helper.cpp"
	"Infrastructure/Helper/Helper.h"
	"Infrastructure/Helper/Exceptions/EnvFileNotExist/EnvFileNotExist.cpp"
	"Infrastructure/Helper/Exceptions/EnvFileNotExist/EnvFileNotExist.h"
	"Infrastructure/Helper/Exceptions/EnvKeyNotExist/EnvKeyNotExist.cpp"
	"Infrastructure/Helper/Exceptions/EnvKeyNotExist/EnvKeyNotExist.h"
	"Infrastructure/Logger/Logger.cpp"
    "Infrastructure/Logger/Logger.h"
)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ConsoleCurrency PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
target_link_libraries(ConsoleCurrency ${Boost_LIBRARIES})
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
file(COPY ${CMAKE_SOURCE_DIR}/.env DESTINATION ${CMAKE_BINARY_DIR})

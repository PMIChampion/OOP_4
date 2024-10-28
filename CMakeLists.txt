cmake_minimum_required(VERSION 3.11)
project(MyNumsProject)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Пути к заголовочным файлам
include_directories(include)

# Добавление исходных файлов
file(GLOB SOURCES "src/*.cpp")
add_library(My_nums_lib STATIC ${SOURCES})

# Добавление основного исполняемого файла
add_executable(My_nums_exe main.cpp)
target_link_libraries(My_nums_exe My_nums_lib)

# Установка и подключение Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# Автоматически добавляем Google Test как поддиректорию
FetchContent_MakeAvailable(googletest)

# Добавление тестов
enable_testing()

# Тестовый исполняемый файл
add_executable(MyNumsTests tests/tests.cpp)
target_link_libraries(MyNumsTests My_nums_lib gtest gtest_main)
add_test(NAME MyNumsTests COMMAND MyNumsTests)

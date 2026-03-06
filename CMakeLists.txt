cmake_minimum_required(VERSION 3.10)
project(CurrencyLib)

# Стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создание статической библиотеки (теперь с двумя классами)
add_library(CurrencyLib STATIC
    src/common/Currency.cpp
    src/common/Stocks.cpp
)

# Включаем заголовочные файлы
target_include_directories(CurrencyLib PUBLIC include)

# Создание тестового приложения
add_executable(CurrencyTest examples/test_app.cpp)
target_link_libraries(CurrencyTest CurrencyLib)

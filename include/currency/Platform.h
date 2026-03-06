#pragma once

// Определение платформы
#if defined(_WIN32) || defined(_WIN64)
    #define CURRENCY_PLATFORM_WINDOWS 1
    #define CURRENCY_PLATFORM_POSIX 0
#elif defined(__linux__)
    #define CURRENCY_PLATFORM_LINUX 1
    #define CURRENCY_PLATFORM_POSIX 1
#else
    #define CURRENCY_PLATFORM_POSIX 1
#endif

// Для статической библиотеки всегда пустой макрос
#define CURRENCY_API

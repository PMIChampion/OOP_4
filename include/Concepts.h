#pragma once
#include <concepts>

template <class T> 
concept Arithmetic = std::is_arithmetic_v<T>;
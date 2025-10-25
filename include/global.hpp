#pragma once

#include<optional>
#include<functional>
#include<vector>

using namespace std;

typedef float real_t;

template<typename T>
using NullableRef = std::optional<std::reference_wrapper<T>>;

template<typename T>
using RefVector = std::vector<std::reference_wrapper<T>>;

#pragma once

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstring>
#include <optional>
#include "z3++.h"

using std::to_string;

#define SIZE(x) std::extent<decltype(x)>::value

// #define VERBOSE // Log events
#ifdef VERBOSE
#define WriteEmptyLine std::cout << std::endl
#define WriteLine(x) std::cout << (x) << std::endl
#define Write(x) std::cout << x
#else
#define WriteEmptyLine
#define WriteLine(x)
#define Write(x)
#endif

typedef std::vector<bool> simple_model;

// For putting z3 expressions in hash-tables
namespace std {

    template<>
    struct hash<simple_model> {
        std::size_t operator()(const simple_model &m) const {
            size_t hash = 0;
            for (unsigned i = 0; i < m.size(); i++) {
                hash *= m.size();
                hash += m[i];
            }
            return hash;
        }
    };

    template<>
    struct hash<z3::expr> {
        std::size_t operator()(const z3::expr &k) const {
            return k.hash();
        }
    };

    // Do not use Z3's == operator in the hash table
    template<>
    struct equal_to<z3::expr> {
        bool operator()(const z3::expr &lhs, const z3::expr &rhs) const {
            return z3::eq(lhs, rhs);
        }
    };
}
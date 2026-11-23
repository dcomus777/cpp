#pragma once
#include <cstdint>
#include <iosfwd>

struct int2026_t
{
    uint_8t data[254]{};
};

static_assert(sizeof(int2026_t) <= 254, "Size of int2026_t must be no higher than 254 bytes");

int2026_t from_int(int32_t i);

int2026_t from_string(const char *buff);

int2026_t operator+(const int2026_t &lhs, const int2026_t &rhs);

int2026_t operator-(const int2026_t &lhs, const int2026_t &rhs);

int2026_t operator*(const int2026_t &lhs, const int2026_t &rhs);

int2026_t operator/(const int2026_t &lhs, const int2026_t &rhs);

bool operator==(const int2026_t &lhs, const int2026_t &rhs);

bool operator!=(const int2026_t &lhs, const int2026_t &rhs);

std::ostream &operator<<(std::ostream &stream, const int2026_t &value);

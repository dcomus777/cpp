#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include "lib/number.h"


TEST(OutputStream, BasicOutput) {
    int2026_t a = from_int(42);
    std::stringstream ss;
    ss << a;
    std::string result = ss.str();
    EXPECT_FALSE(result.empty());
}

TEST(OutputStream, NegativeNumberOutput) {
    int2026_t a = from_int(-42);
    std::stringstream ss;
    ss << a;
    std::string result = ss.str();
    EXPECT_FALSE(result.empty());
}

TEST(OutputStream, ZeroOutput) {
    int2026_t zero = from_int(0);
    std::stringstream ss;
    ss << zero;
    std::string result = ss.str();
    EXPECT_FALSE(result.empty());
}

TEST(OutputStream, LargeNumberOutput) {
    int2026_t large = from_string("12345678901234567890123456789012345678901234567890");
    std::stringstream ss;
    ss << large;
    std::string result = ss.str();
    EXPECT_FALSE(result.empty());
}

TEST(OutputStream, VeryLargeNumberOutput) {
    int2026_t very_large = from_string("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
    std::stringstream ss;
    ss << very_large;
    std::string result = ss.str();
    EXPECT_FALSE(result.empty());
}

TEST(OutputStream, MultipleOutputToSameStream) {
    int2026_t a = from_int(123);
    int2026_t b = from_int(456);
    std::stringstream ss;
    ss << a << " " << b;
    std::string result = ss.str();
    EXPECT_FALSE(result.empty());
}

TEST(OutputStream, OutputConsistency) {
    int2026_t a = from_int(42);
    int2026_t b = from_int(42);

    std::stringstream ss1, ss2;
    ss1 << a;
    ss2 << b;

    EXPECT_EQ(ss1.str(), ss2.str());
}

TEST(OutputStream, OutputInequalityFromInt) {
    int2026_t a = from_int(566);
    int2026_t b = from_int(239);

    std::stringstream ss1, ss2;
    ss1 << a;
    ss2 << b;
    EXPECT_FALSE(ss1.str() == ss2.str());
}

TEST(OutputStream, OutputInequalityFromString) {
    int2026_t a = from_string("5661234567890566");
    int2026_t b = from_string("5661234567890567");

    std::stringstream ss1, ss2;
    ss1 << a;
    ss2 << b;
    EXPECT_FALSE(ss1.str() == ss2.str());
}

TEST(OutputStream, ReturnsTheSameStream) {
    std::stringstream stream;
    EXPECT_EQ(&(stream << from_int(42)), &stream);
}

TEST(OutputStream, ChainingPreservesBothValuesAndSeparator) {
    std::stringstream left, right, combined;
    left << from_int(123);
    right << from_int(-456);
    combined << from_int(123) << "|" << from_int(-456);
    EXPECT_EQ(combined.str(), left.str() + "|" + right.str());
}

TEST(OutputStream, DistinguishesSignAndZero) {
    std::stringstream positive, negative, zero;
    positive << from_int(42);
    negative << from_int(-42);
    zero << from_int(0);
    EXPECT_NE(positive.str(), negative.str());
    EXPECT_NE(positive.str(), zero.str());
    EXPECT_NE(negative.str(), zero.str());
}

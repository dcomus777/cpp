#include <iostream>

int square(int x)
{
    return x * x;
}

int main()
{
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "Square for number " << number << " is " << square(number);
    return 0;
}
//
// Created by Ahoge Knight on 2022/8/12.
//

#include <iostream>

int main() {
    int x = 0;
    std::cout << "42 == x " << (42 == x) << '\n'; // Equality
    std::cout << "42 != x " << (42 != x) << '\n'; // Inequality
    std::cout << "100 > x " << (100 > x) << '\n'; // greater than
    std::cout << "123 >= x " << (123 >= x) << '\n'; //Greater than or equal to
    std::cout << "-10 < x " << (-10 < x) << '\n'; // Less than
    std::cout << "-99 <= x " << (-99 <= x) << '\n'; // Less than or equal to
    return 0;
}
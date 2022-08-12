//
// Created by Ahoge Knight on 2022/8/12.
//

#include <iostream>

int step_function(int x) {
    int result = 0;
    if (x < 0) result = -1;
    else if (x > 0) result = 1;
    return result;
}

int main() {
    std::cout << "step function 100: " << step_function(-100) << '\n';
    std::cout << "step function 10: " << step_function(10) << '\n';
    std::cout << "step function 0: " << step_function(0) << std::endl;
}
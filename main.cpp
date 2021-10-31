#include <iostream>
#include "part_1/listing_2.cuh"
#include "part_1/exercise_2.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Calculator pCalculator{Operation::Add};
    std::cout << pCalculator.calculate(1, 2) << std::endl;
    return 0;
}
#include <iostream>
#include "part_1/listing_2.cuh"

int main() {
    std::cout << "Hello, World!" << std::endl;
    listing_2_12();
    Race longobard_race = Race::Aidan;
    std::cout << static_cast<int>(longobard_race) << std::endl;
    return 0;
}

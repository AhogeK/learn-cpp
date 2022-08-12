//
// Created by ahogek on 1/3/22.
//

#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

int main() {
    std::vector<const char *> cats{"Heathcliff", "Snagglepuss", "Hobbes", "Garfield"};
    std::sort(cats.begin(), cats.end(), [](const char *strA, const char *strB) {
        return std::strcmp(strA, strB) < 0;
    });

    for (const char *cat: cats) {
        std::cout << cat << '\n';
    }
    return 0;
}
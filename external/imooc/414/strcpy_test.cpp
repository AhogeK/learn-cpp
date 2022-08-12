//
// Created by ahogek on 1/3/22.
//

#include <memory>
#include <cstring>
#include <iostream>

int main() {
    const char *src = "Take the test.";
    //  src[0] = 'M'; // can't modify string literal
    auto dst = std::make_unique<char[]>(std::strlen(src) + 1); // +1 for the null terminator
    std::strcpy(dst.get(), src);
    dst[0] = 'M';
    std::cout << src << '\n' << dst.get() << '\n';
}
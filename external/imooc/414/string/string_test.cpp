//
// Created by ahogek on 1/3/22.
//

#include <string>
#include <iostream>

int main() {
    // Creating a string from const char*
    std::string string1 = "hello";

    using namespace std::literals;
    // Creating a string using string literal
    auto string2 = "world"s;

    // Concatenating strings
    std::string string3 = string1 + " " + string2;

    // Print out the result
    std::cout << string3 << '\n';

    std::string::size_type pos = string3.find(' ');
    string1 = string3.substr(pos + 1); // the part after the space
    string2 = string3.substr(0, pos);  // the part till the space

    std::cout << string1 << ' ' << string2 << '\n';

    // Accessing an element using subscript operator[]
    std::cout << string1[0] << '\n';
    string1[0] = 'W';
    std::cout << string1 << '\n';
    std::cout << "length " << string1.length() << '\n';
    std::cout << "size " << string1.size() << '\n';
    std::cout << "capacity " << string1.capacity() << '\n';
    return 0;
}
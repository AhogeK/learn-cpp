//
// Created by ahogek on 1/7/22.
//

#include <ostream>
#include <iostream>

// enum that takes 16 bats
enum samllenum : std::int16_t {
    a,
    b,
    c
};

// color maybe red value 0, yellow value 1, green value 20, or blue value 21
enum color {
    red,
    yellow,
    green = 20,
    blue
};

// altitude maybe altitude::high or altitude::low
enum altitude {
    high = 'h',
    low = 'l', // c++11 allows the extra comma
};

// the constant d is 0, the constant e is 1, the constant f is 3
enum {
    d,
    e,
    f = e + 2
};

// enumeration types (both scoped and unscoped) can have overloaded operators
std::ostream &operator<<(std::ostream &os, color c) {
    switch (c) {
        case red:
            os << "red";
            break;
        case yellow:
            os << "yellow";
            break;
        case green:
            os << "green";
            break;
        case blue:
            os << "blue";
            break;
        default:
            os.setstate(std::ios_base::failbit);
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, altitude al) {
    return os << static_cast<char>(al);
}

// the scoped enum (C++ 11) can be partially emulated in earlier C++ revisions
enum struct E11 {
    x, y
}; // since c++ 11

struct E98 {
    enum {
        x, y
    };
}; // ok in pre-c++ 11

namespace N98 {
    enum {
        x, y
    };
} // ok in pre-c++ 11

struct S98 {
    static const int x = 0, y = 1;
}; // ok in pre-c++ 11

void emu() {
    std::cout << static_cast<int>(E11::y) + E98::y + N98::y + S98::y << '\n';
}

namespace cxx20 {
    enum class long_long_long_name {
        x, y
    };

    void using_enum_demo() {
        std::cout << "C++ 20 using enum: __cpp_using_enum == ";
        switch (auto rnd = [] { return long_long_long_name::x; }; rnd()) {
# if defined(__cpp_using_enum)
            using enum long_long_long_name;
            case x: std::cout << __cpp_using_enum << "; x\n"; break;
            case y: std::cout << __cpp_using_enum << "; y\n"; break;
#else
            case long_long_long_name::x:
                std::cout << "?; x\n";
                break;
            case long_long_long_name::y:
                std::cout << "?; y\n";
                break;
#endif
        }
    }
}

int main() {
    color col = red;
    altitude a;
    a = altitude::low;
    std::cout << "col = " << col << '\n'
              << "a = " << a << '\n'
              << "f = " << f << '\n';
    cxx20::using_enum_demo();
}
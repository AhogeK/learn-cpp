# learn-cpp

> cpp 学习代码练习

## 目录

* C++ CRASH COURSE
    * [1 UP AND RUNNING](doc/book/c++-crash-course/1-up-and-running.md)
* imooc 414
  * [字符串相关内容](doc/imooc/414/字符串.md)
  * [指针引用相关内容](doc/imooc/414/指针引用相关.md)
  * [enum](#enum)
  * [结构体与联合体](#结构体与联合体)
  * [结构体的内部布局](#结构体的内部布局)

#### 2 TYPES

##### Fundamental Types

###### Listing 2-1

> Listing 2-1: A program that assigns several integer variables and prints them with the appropriate format specifier

```c++
/**
 * 一个指定一些整型变量利用不同的进制进行打印的程序
 */
void listing_2_1() {
    unsigned short a = 0b10101010;
    printf("%hu\n", a);
    int b = 0123;
    printf("%d\n", b);
    unsigned long long d = 0xFFFFFFFFFFFFFFF;
    printf("%llu\n", d);
}
```

###### Listing 2-2

> Listing 2-2: A program that uses octal and hexadecimal representations of unsigned integers

```c++
/**
 * 打印十六进制，十进制，八进制
 */
void listing_2_2() {
    unsigned int a = 3669732608;
    printf("Yabba %x!\n", a);
    unsigned int b = 69;
    printf("There are %u, %o leaves here. \n", b, b);
}
```

###### Listing 2-3

> Listing 2-3: A program printing several floating points

```c++
void listing_2_3() {
    double an = 6.0221409e23;
    /* l 代表 double le 科学计数 lf 普通计数 lg 计算机选择最合适的计数方式 */
    printf("Avogaadro's Number: %le %lf %lg\n", an, an, an);
    float hp = 9.75;
    printf("Hogwarts' Platform: %e %f %g\n", hp, hp, hp);
}
```

## External

> External 代表非 《C++ CRASH COURSE》中的内容，目前 ``external`` 中的练习为 慕课C++课程练习内容

### enum

```c++
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
```

### 结构体与联合体

```c++
#include <iostream>

using namespace std;

// Define structure
struct Test {
    int T1;
    char T2;
    float T3;
};

// Declaration of typedef
using TT = struct TestTypedef {
    int TT1;
    char TT2;
    float TT3;
};

// Defining a Union
union TestUnion {
    struct {
        int U1;
        char U2;
        float U3;
    } one;
};

int main() {
    // Declaring a Structure
    struct Test test;
    test.T1 = 1;
    test.T2 = '2';
    test.T3 = 3.3f;

    cout << " T1: " << test.T1 << "\n"
         << " T2: " << test.T2 << "\n"
         << " T3: " << test.T3 << "\n";

    TT tt;
    tt.TT1 = 11;
    tt.TT2 = 'b';
    tt.TT3 = 33.33f;

    cout << " TT1: " << tt.TT1 << "\n"
         << " TT2: " << tt.TT2 << "\n"
         << " TT3: " << tt.TT3 << "\n";

    union TestUnion U1{};
    U1.one.U1 = 64;
    U1.one.U2 = 64;
    U1.one.U3 = 64.64f;
    // Printing values
    cout << U1.one.U1 << "\n";

    cout << U1.one.U2 << "\n";

    cout << U1.one.U3 << "\n";
    return 0;
}
```

### 结构体的内部布局

```c++
#include <cstdio>

// Alignment requirements
// (typical 32 bit machine)

// char         1 byte
// short int    2 bytes
// int          4 bytes
// double       8 bytes

// structure A

using structa_t = struct structa_tag {
    char c;
    short int s;
};

// structure B
using structb_t = struct structb_tag {
    short int s;
    char c;
    int i;
};

// structure C
using structc_t = struct structc_tag {
    char c;
    double d;
    int s;
};

// structure D
using structd_t = struct structd_tag {
    double d;
    int s;
    char c;
};

int main() {
    printf("sizeof(structa_t) = %lu\n", sizeof(structa_t));
    printf("sizeof(structb_t) = %lu\n", sizeof(structb_t));
    printf("sizeof(structc_t) = %lu\n", sizeof(structc_t));
    printf("sizeof(structd_t) = %lu\n", sizeof(structd_t));

    return 0;
}
```

结构体的内存布局关键在于数据对齐，例如 ``structb_t`` 包含 ``short int`` 两字节而 ``char`` 一字节
两个相加不满四字节，但算上 ``int`` 的四字节又超了四字节所以 ``short int`` 与 ``char`` 组一起并补满四字节
并加上 ``int`` 的四字节, 所以 ``structb_t`` 为 8 字节 即 64 位系统的一组

又例如 ``structc_t`` 包含 ``char`` 一字节 ``double`` 八字节 两个相加超了八字节，所以 ``double`` 单个八字节一组，
因为 64 位系统的关系，``char`` 需要补七字节满八字节，而最后 ``int`` 为四字节，因为要与上 ``double`` 的八字节对齐，因此
``int`` 也要补四字节满八字节，所以 ``structc_t`` 总要占 24 字节

而例如最后的 ``structd_t``, 第一个为 ``double`` 自满八字节一组, 而 ``int`` 为四字节不能八字节余下的四字节够 ``char`` 的一字节使用, 
剩下的三字节在于 ``double`` 对齐补满, 所以总占 16 字节
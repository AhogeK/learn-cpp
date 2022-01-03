# learn-cpp

> cpp 学习代码练习

## 目录

* [External](#external)
  * [strlen](#strlen)
  * [strcmp](#strcmp)
  * [strcpy](#strcpy)
  * [string](#string)
  * [内存单元与地址](#内存单元与地址)
  * [指针数组与数组指针](#指针数组与数组指针)

## External

> External 代表非 《C++ CRASH COURSE》中的内容，目前 ``external`` 中的练习为 慕课C++课程练习内容

### strlen

external/strlen_test.cpp

```c++
#include <cstdio>
#include <cstring>

int main() {
    char szInput[256];
    std::FILE *tmpf = std::tmpfile();
    std::fputs("Just Testing", tmpf);

    std::rewind(tmpf);
    char buf[8];
    int index = 0;
    while (std::fgets(buf, sizeof buf, tmpf) != nullptr) {
        if (index != 0 && buf[index--] == '\000') index--;
        for (char i: buf) {
            szInput[index++] = i;
        }
    }
    printf("The sentence entered is %u characters long.\n", (unsigned) strlen(szInput));
    printf("szInput length is %u\n", (unsigned) (sizeof szInput / sizeof szInput[0]));
    return 0;
}
```

* ``std::tmpfile``
  * 创建一个临时文件
* ``std:fputs``
  * 空字符结尾的字符串写入至指定的文件流
* ``std::rewind``
  * 移动文件的位置指针至初始位置
* ``strlen``
  * C 函数库，返回c字符串长度 [std::strlen](https://en.cppreference.com/w/cpp/string/byte/strlen) 为C++函数库的strlen函数

### strcmp

external/strcmp_test.cpp

```c++
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
```

* ``std::sort``
  * 排序函数，可通过第三个参数利用lambda自定义，return true 位置不变，false交换
* ``std::strcmp``
  * 比较两个字符串，以首字母的asc码进行比较，左比右小负数，相同为0，左比右大正数，首字母相同会接着往下逐个比较

### strcpy

external/strcpy_test.cpp

```c++
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
```

* ``std::make_unique``
  * 构建一个对象被并 [std::unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr) 包装
* ``std::strcpy``
  * 字符串拷贝，包括 null 终止符

*声明的char指针字符串不能对里面的字符进行修改，但可以通过 ``strcpy`` 拷贝至新建的char数组，数组可以修改当中的字符元素*

### string

external/string_test.cpp

```c++
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

    std::string::size_type pos = string3.find(" ");
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
```

* ``std::string``
  * C++加入的字符串对象
* ``std::liternals`` -> ``std::literals::string_literals::operator""s``
  * 生成一个``std::string`` 字符串直接量
* ``std::string::find``
  * 在字符串中寻找指定字符串返回其下标，如果未找到会返回 ``string::npos``
* ``std::string::substr``
  * 截取字符串中的一节生成新的字符串
* ``std::string::length`` ``std::string::size``
  * 获取字符串的长度
* ``std::string::capacity``
  * 获取这个字符串容器的总容量

### 内存单元与地址

external/memory_cells_address_test.cpp

```c++
#include <iostream>

int main() {
    std::cout << "##################### 内存单元与地址 #######################" << '\n';
    int a = 112;
    float b = 3.14f;
    int *c = &a;
    float *d = &b;
    std::cout << "a = 112 | b = 3.14f | *c = &b | *d = &b" << '\n';
    std::cout << "a " << a << '\n';
    std::cout << "b " << b << '\n';
    std::cout << "c " << c << '\n';
    std::cout << "d " << d << '\n';
    std::cout << "&a " << &a << '\n';
    std::cout << "&b " << &b << '\n';
    std::cout << "&c " << &c << '\n';
    std::cout << "&d " << &d << '\n';
    std::cout << "c[0] " << c[0] << '\n';
    std::cout << "d[0] " << d[0] << '\n';
    std::cout << "*c " << *c << '\n';
    std::cout << "*d " << *d << '\n';
}
```

**这里主要认识 ``*`` 与 ``&`` 存取的区别，a 存储的是直接量 112，这个112有一个指定的地址位置即 &a，它可以被指针 ``*c`` 接收， 即 ``*c = &a`` 而此时 c即指针也有属于他自己的地址，并存储着
a的地址，所以``*c``遍可以获取到112**

### 指针数组与数组指针

external/pointer_array_test.cpp

```c++
#include <iostream>

using namespace std;

int main() {
    // Pointer to an integer
    int *p;

    // Pointer to an array of 5 integers
    int (*ptr)[5];
    int arr[5] = {1, 2, 3, 4, 5};

    // Points to 0th element of the arr.
    p = arr;

    // Points to the whole array arr.
    ptr = &arr;

    cout << "p = " << p << ", ptr = " << ptr << endl;
    cout << "p = " << *p << ", ptr = " << **ptr << endl;
    p++;
    ptr++;
    cout << "p = " << p << ", ptr = " << ptr << endl;
    cout << "p = " << *p << ", ptr = " << **ptr << endl;
    return 0;
}
```

这里的代码主要用于学习区分指针数组还是数组指针，即 "Difference between pointer to an array and array of pointers"。
区别在于一个是一个指针存储一个数组地址，而另一个是数组里的一个元素为一个指针，有序序列，后每一个元素都为前一个元素指针+1
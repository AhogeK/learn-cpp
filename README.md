# learn-cpp

> cpp 学习代码练习

## 目录

* [External](#external)
  * [strlen](#strlen)
  * [strcmp](#strcmp)
  * [strcpy](#strcpy)

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
    return 0;https://en.cppreference.com/w/cpp/memory/unique_ptr
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
# learn-cpp

> cpp 学习代码练习

## External
> External 代表非 《C++ CRASH COURSE》中的内容，目前 ``external`` 中的练习为 慕课C++课程练习内容

external/strlenTest.cpp

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
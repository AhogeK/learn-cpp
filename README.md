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
  * [const pointer](#const-pointer)
  * [double pointer](#double-pointer)
  * [illegal pointer](#illegal-pointer)
  * [两种指针+1的区别](#两种指针+1的区别)
  * [不同指针自增的区别](#不同指针自增的区别)
  * [RAII](#raii)
  * [栈堆的区别](#栈堆的区别)
  * [引用](#引用)
  * [enum](#enum)

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

C++ 中每行代码在内存中都会有相应的内存存储地址

例如:

全局变量在 (GVAR)全局初始化区 (bss)全局未初始化区

实际大括号阔起的代码区会被 (text)代码区包围

代码区内的变量为 (stack)栈区变量，常量会在常量区

静态量会在全局静态初始化区

对象变量为 (heap)堆区变量

#### Memory Layout of C Programs

C 语言在内存中的组成：

* Text segment (i.e. instructions)
* Initialized data segment
* Uninitialized data segment  (bss)
* Heap
* Stack

![memory layout of c programs](https://media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg)

```c++
int global; /* Uninitialized variable stored in bss*/
int global2 = 10; /* initialized global variable stored in DS*/

int main() {
    static int i; /* Uninitialized static variable stored in bss */
    static int j = 100; /* Initialized static variable stored in DS*/
    return 0;
}
```

可以使用 ``gcc`` 编译后用 ``size`` 指令查看 ``text data bss dec hex``

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

### const pointer

external/const_pointer_test.cpp

```c++
#include <iostream>

int main() {
    int high{100};
    int low{66};
    const int *score{&high};
    // Pointer variable are read from
    // the right to left
    std::cout << *score << " via score change ";
    // Score is a pointer to integer
    // which is constant *score = 78
    // Error: *score = 78;
    // It will give you an Error:
    // assignment of read-only location
    // ‘* score’ because value stored in
    // constant cannot be changed
    score = &low;
    // This can be done here as we are
    // changing the location where the
    // score points now it points to low
    std::cout << *score << "\n";

    int numberA{90};
    int numberB{50};
    int *const ptr{&numberA};
    std::cout << *ptr << " ";
    std::cout << ptr << "\n";
    // Address what it points to
    *ptr = 56;
    // Acceptable to change the
    // value of numberA
    // Error: assignment of read-only
    // variable ‘ptr’
    // ptr = &numberB;
    std::cout << *ptr << " ";
    std::cout << ptr << "\n";

    // ptr points to a
    const int *const ptr2{&numberA};
    // *ptr = 90;
    // Error: assignment of read-only
    // location ‘*(const int*)ptr’
    // ptr = &numberB;
    // Error: assignment of read-only
    // variable ‘ptr’
    // Address of a
    std::cout << ptr << " ";
    // Value of a
    std::cout << *ptr << "\n";
}
```

这里的代码用于区别 C++ 中 **constant pointer** | **pointer to constant** | **constant pointer to constant**

非别代表 **指针不能修改替换为其他指针但指针存储的值地址可以被修改** | **指针存储的值地址不能被修改，但指针为变量可以修改为别的指针** | **两者均不能修改**

### double pointer

external/double_pointer_test.cpp

```c++
#include <cstdio>

int main() {
    int variable = 789;
    // pointer for variable
    int *pointer2;
    // double pointer for ptr2
    int **pointer1;
    // storing address of var in ptr2
    pointer2 = &variable;
    // Storing address of ptr2 in ptr1
    pointer1 = &pointer2;
    // Displaying value of var using
    // both single and double pointers
    printf("Value of var = %d\n", variable);
    printf("Value of var using single pointer = %d\n", *pointer2 );
    printf("Value of var using double pointer = %d\n", **pointer1);
    return 0;
}
```

双指针，代码中 pointer2 指针指向整型变量789, 而指针 pointer1 指向指针 pointer2, pointer1 便是双指针

### illegal pointer

external/illegal_pointer_test.cpp

```c++
#include <cstdio>

int main() {
    int some = 20;
    int *iptr = &some;  /* iptr initialized with address of 'some' */
    printf("\nAddress of integer \'some\' in exp. \'int some = 20\' is %p\n"
           "and where \'iptr\' is pointing to, in exp. 'int *iptr = &some',"
           " is\n%p\n", &some, iptr);
    printf("\nLet's see what happens when we access initialized pointer "
           "\'ptr\' in exp.\n\'int *iptr = &some\'\n");
    printf("This gives Value %d of variable \'some\'\n\n", *iptr);

    int *ip1;   /* ip1 declared pointer-to-integer, but not initialized */
    int *ip2;   /* ip2 declared pointer-to-integer, but not initialized */
    char *cp;   /* cp declared pointer-to-character, but not initialized */
    float *fp;  /* fp declared pointer-to-float, but not initialized */
    printf("Default Address \'ip1\' holds as %p\n", ip1);
    printf("Default Address \'ip2\' holds as %p\n", ip2);
    printf("Default Address \'cp\' holds as %p\n", cp);
    printf("Default Address \'fp\' holds as %p\n", fp);
    printf("\nNow, see, what happens when we access uninitialized pointers"
           "...\n");
    printf("%d %d %c %f\n", *ip1, *ip2, *cp, *fp);
    return 0;
```

这里的这段代码主要展示了C中当使用输出未初始化不合法的指针会发生什么。

建议指针变量都可以设置成 指针指向的值为 const 不让修改，但该指针变量可以为其他指针，这样的目的是为了避免被其它错误代码误访问并修改。 例如 ``int *const var``
杜绝野指针

* 指针变量没有初始化
* 被释放的指针没有设置NULL
* 指针操作超越了变量范围

**没有初始化的，不用的，超出范围的指针的指针建议设置成 NULL/nullptr**

大量的空指针野指针会造成内存泄露问题

* 使用智能指针
* 使用引用

### 两种指针+1的区别

* *p + 1
  * 代表指针存储的指向的地址的值+1 如 *p = 1 则 *p + 1 = 2
* *(p + 1)
  * 代表指针的地址+1

### 不同指针自增的区别

```c++
#include <cstdio>

int main() {
    int arr[] = {10, 20, 30};
    int *p = arr;
    printf("arr[0] = %d, arr[1] = %d, *p = %d\n",
           arr[0], arr[1], *p);
    // 指针值自增
    ++*p;
    printf("arr[0] = %d, arr[1] = %d, *p = %d\n",
           arr[0], arr[1], *p);
    // 指针地址自增
    *p++;
    printf("arr[0] = %d, arr[1] = %d, *p = %d\n",
           arr[0], arr[1], *p);
    // 指针地址自增
    *++p;
    printf("arr[0] = %d, arr[1] = %d, *p = %d",
           arr[0], arr[1], *p);
    return 0;
}
```

### RAII

```c++
#include <mutex>
#include <iostream>

std::mutex m;

void f() {
    throw std::runtime_error("111");
}

bool everything_ok() {
    std::cout << "ok" << "\n";
    return true;
}

void bad()
{
    m.lock();                    // acquire the mutex
    f();                         // if f() throws an exception, the mutex is never released
    if(!everything_ok()) return; // early return, the mutex is never released
    m.unlock();                  // if bad() reaches this statement, the mutex is released
}

void good()
{
    std::lock_guard<std::mutex> lk(m); // RAII class: mutex acquisition is initialization
    f();                               // if f() throws an exception, the mutex is released
    if(!everything_ok()) return;       // early return, the mutex is released
}
```

总结

* 封装资源到 class
  * 在构造获取资源，如果获取不到设置其默认值，或抛出异常
  * 在解构释放资源，不再抛出异常
* 要通过 RAII class 实例来获取使用资源
  * 有自动存储持续时间
  * 在自动或临时对象拥有界定的生命周期

**Classes with open()/close(), lock()/unlock(), or init()/copyFrom()/destroy() member functions are typical examples of
non-RAII classes**

RAII 标准库

* std::string
* std::vector
* std::jthread
* 标准封装库
  * std::auto_ptr
    * ```c++
      #include <memory>
      #include <iostream>

      int main() {
          std::auto_ptr<int> p1 (new int);
          *p1.get()=10;

          std::auto_ptr<int> p2 (p1);

          std::cout << "p2 points to " << *p2 << '\n';
          // (p1 is now null-pointer auto_ptr)
          // std::cout << "p1 " << *p1 << '\n';
          return 0;
      }
      ```
      [更多](https://www.cplusplus.com/reference/memory/auto_ptr/)
  * std::unique_ptr
    * ```c++
      #include <iostream>
      #include <memory>

      int main() {
                                                      // foo   bar    p
                                                      // ---   ---   ---
          std::unique_ptr<int> foo;                   // null
          std::unique_ptr<int> bar;                   // null  null
          int *p = nullptr;                           // null  null  null

          foo = std::unique_ptr<int>(new int(10));    // (10)  null  null
          bar = std::move(foo);                       // null  (10)  null
          p = bar.get();                              // null  (10)  (10)
          *p = 20;                                    // null  (20)  (20)
          p = nullptr;                                // null  (20)  null

          foo = std::unique_ptr<int>(new int(30));    // (30)  (20)  null
          p = foo.release();                          // null  (20)  (30)
          *p = 40;                                    // null  (20)  (40)

          std::cout << "foo: ";
          if (foo) std::cout << *foo << '\n'; else std::cout << "(null)\n";

          std::cout << "bar: ";
          if (bar) std::cout << *bar << '\n'; else std::cout << "(null)\n";

          std::cout << "p: ";
          if (p) std::cout << *p << '\n'; else std::cout << "(null)\n";
          std::cout << '\n';

          delete p;   // the program is now responsible of deleting the object pointed to by p
                      // bar deletes its managed object automatically
          return 0;
      }
      ```
      [更多](https://www.cplusplus.com/reference/memory/unique_ptr/)
  * std::shared_ptr
    * ```c++
      #include <memory>
      #include <iostream>
      
      struct C {int* data;};
      
      int main() {
      std::shared_ptr<int> p1;
      std::shared_ptr<int> p2 (nullptr);
      std::shared_ptr<int> p3 (new int);
      std::shared_ptr<int> p4 (new int, std::default_delete<int>());
      std::shared_ptr<int> p5 (new int, [](int* p){delete p;}, std::allocator<int>());
      std::shared_ptr<int> p6 (p5);
      std::shared_ptr<int> p7 (std::move(p6));
      std::shared_ptr<int> p8 (std::unique_ptr<int>(new int));
      std::shared_ptr<C> obj (new C);
      std::shared_ptr<int> p9 (obj, obj->data);
      
          std::cout << "use_count:\n";
          std::cout << "p1: " << p1.use_count() << '\n';
          std::cout << "p2: " << p2.use_count() << '\n';
          std::cout << "p3: " << p3.use_count() << '\n';
          std::cout << "p4: " << p4.use_count() << '\n';
          std::cout << "p5: " << p5.use_count() << '\n';
          std::cout << "p6: " << p6.use_count() << '\n';
          std::cout << "p7: " << p7.use_count() << '\n';
          std::cout << "p8: " << p8.use_count() << '\n';
          std::cout << "p9: " << p9.use_count() << '\n';
          return 0;
      }
      ```
      [更多](https://www.cplusplus.com/reference/memory/shared_ptr/)
  * std::std::week_ptr
    * ```c++
      #include <memory>
      #include <iostream>
      
      struct C {int* data;};
      
      int main () {
          std::shared_ptr<int> sp (new int);
      
          std::weak_ptr<int> wp1;
          std::weak_ptr<int> wp2 (wp1);
          std::weak_ptr<int> wp3 (sp);
      
          std::cout << "use_count:\n";
          std::cout << "wp1: " << wp1.use_count() << '\n';
          std::cout << "wp2: " << wp2.use_count() << '\n';
          std::cout << "wp3: " << wp3.use_count() << '\n';
      
          return 0;
      }
      ```
      **weak_ptr 被设计为与 shared_ptr共同工作避免发生循环引用**

      [更多](https://www.cplusplus.com/reference/memory/weak_ptr/)
  * std::lock_guard
  * std::unique_lock
  * std::shared_lock

#### 循环引用问题

```c++
#include <iostream>
#include <memory> // for std::shared_ptr
#include <string>

class Person
{
    std::string m_name;
    std::shared_ptr<Person> m_partner; // initially created empty

public:

    Person(const std::string &name): m_name(name)
    {
        std::cout << m_name << " created\n";
    }
    ~Person()
    {
        std::cout << m_name << " destroyed\n";
    }

    friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
    {
        if (!p1 || !p2)
            return false;

        p1->m_partner = p2;
        p2->m_partner = p1;

        std::cout << p1->m_name << " is now partnered with " << p2->m_name << "\n";

        return true;
    }
};

int main()
{
    auto lucy { std::make_shared<Person>("Lucy") }; // create a Person named "Lucy"
    auto ricky { std::make_shared<Person>("Ricky") }; // create a Person named "Ricky"

    partnerUp(lucy, ricky); // Make "Lucy" point to "Ricky" and vice-versa

    return 0;
}
```

[关于更多该代码与循环引用的详细](https://www.learncpp.com/cpp-tutorial/circular-dependency-issues-with-stdshared_ptr-and-stdweak_ptr/)

### 栈堆的区别

![stack and heap](https://ahogek-oss.oss-cn-hangzhou.aliyuncs.com/blog-img/2022-01-06_14-36.png)

**[Stack vs Heap Memory Allocation](https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/)**

```c++
int main() {
    // All these variables get memory
    // allocated on stack
    int a;
    int b[10];
    int n = 20;
    int c[n];

    // This memory for 10 integers
    // is allocated on heap.
    int *ptr  = new int[10];
    return 0;
}
```

### 引用

```c++
#include <string>
#include <iostream>

using namespace std;

int main() {
    string food = "Pizza";
    string &meal = food;

    cout << food << "\n";  // Outputs Pizza
    cout << meal << "\n";  // Outputs Pizza
}
```

引用是一种特殊的指针，不允许修改的指针，支持函数运算符的重载，兼容C语言

- 不存在空引用
- 必须初始化
- 一个引用永远指向它初始化的那个对象

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
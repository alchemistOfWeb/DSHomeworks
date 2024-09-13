#include <iostream>
#include <stdexcept>
#include <initializer_list> 

#if __cplusplus >= 202002L
    #include "MyArray.h"
#else
    import MyArray;
#endif


int main() {
    std::cout << "Hello World!\n";
    MyArray<int, 3> a {1, 4, 3};
    MyArray<int, 3> b {1, 2, 3};
    MyArray<int, 3> c {1, 2, 3};
    std::cout << "a == b: " << (a == b) << std::endl;
    a.swap(c);
    std::cout << "a == b: " << (a == b) << std::endl;

    MyArray<int, 3> a1 {1, 2, 3};
    MyArray<int, 3> a2 {1, 2, 3};
    std::cout << "a <= b: " << (a1 <= a2) << std::endl;
}

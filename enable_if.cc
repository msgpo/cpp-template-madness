#include <iostream>
#include <type_traits>


template <bool, typename T = void>
struct enable_if {
    typedef T type;
};

template <typename T>
struct enable_if<false, T> {};

template <bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type;


template <typename T>
enable_if_t<std::is_integral<T>::value, bool> equals(T a, T b) {
    std::cout << "integral comparison" << std::endl;
    return false;
}

template <typename T>
enable_if_t<std::is_floating_point<T>::value, bool> equals(T a, T b) {
    std::cout << "floating comparison" << std::endl;
    return true;
}


int main() {
    equals(1, 1);
    equals('a', 'b');
    equals(1.0f, 1.0f);
    equals(1.0, 1.0);
    return 0;
}

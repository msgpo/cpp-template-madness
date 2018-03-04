#include <iostream>
#include <string>
#include <type_traits>


template <typename... Types>
using void_t = void;

template <typename T, typename = void>
struct has_secret_t : std::false_type {};

template <typename T>
struct has_secret_t<T, void_t<decltype(T::sicrit)>> : std::true_type {};


struct foo1 {
    std::string message;
};

struct foo2 {
    std::string sicrit; // super secret string
};


int
main() {
    std::cout << has_secret_t<foo1>::value << std::endl;
    std::cout << has_secret_t<foo2>::value << std::endl;
    return 0;
}

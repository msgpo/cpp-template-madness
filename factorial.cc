
#include <iostream>


template <int N>
struct factorial {
    constexpr static int value = N * factorial<N-1>::value;
};

template <>
struct factorial<0> {
    constexpr static int value = 1;
};


int
main() {
    std::cout << "5! = " << (factorial<5>::value) << std::endl;
    return 0;
}


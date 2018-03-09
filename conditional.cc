#include <iostream>


template <bool, typename T, typename U>
struct conditional {
    typedef T type;
};

template <typename T, typename U>
struct conditional<false, T, U> {
    typedef U type;
};

template <bool B, typename T, typename U>
using conditional_t = typename conditional<B, T, U>::type;


struct Foo {
    void operator()() {
        std::cout << "foo" << std::endl;
    }
};

struct Bar {
    void operator()() {
        std::cout << "bar" << std::endl;
    }
};


int main() {
    conditional_t<true, Foo, Bar> foo;
    foo();

    conditional_t<false, Foo, Bar> bar;
    bar();

    return 0;
}

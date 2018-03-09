#include <iostream>
#include <type_traits>


template <typename T>
using move_assignment_t = decltype(std::declval<T&>() = std::declval<T&&>());

template <typename T, typename = void>
struct is_move_assignable : std::false_type
{
};

template <typename T>
struct is_move_assignable<T, std::void_t<move_assignment_t<T>>>
    : std::is_same<move_assignment_t<T>, T&>
{
};


class Foo {
public:
    Foo(int pizza = 42)
        : m_pizza(pizza)
    {
    }

private:
    int m_pizza;
};

class Bar {
public:
    Bar(int pizza = 42)
        : m_pizza(pizza)
    {
    }

    Bar& operator = (Bar&& other) = delete;

private:
    int m_pizza;
};


int main() {
    std::cout << is_move_assignable<Foo>::value << std::endl;
    std::cout << is_move_assignable<Bar>::value << std::endl;
    return 0;
}

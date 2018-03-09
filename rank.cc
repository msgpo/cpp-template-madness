#include <iostream>
#include <type_traits>


template <typename T>
struct rank
    : std::integral_constant<size_t, 0>
{
};

template <typename T, size_t N>
struct rank<T[N]>
    : std::integral_constant<size_t, 1 + rank<T>::value>
{
};

template <typename T>
struct rank<T[]>
    : std::integral_constant<size_t, 1 + rank<T>::value>
{
};


int main() {
    std::cout << rank<int>::value << std::endl;
    std::cout << rank<int[10][20][42]>::value << std::endl;
    std::cout << rank<int[][20][42]>::value << std::endl;
    return 0;
}

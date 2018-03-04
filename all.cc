#include <iostream>
#include <type_traits>


template <template <typename> class Op>
constexpr bool all_f() {
    return true;
}

template <template <typename> class Op, typename T, typename... Types>
constexpr bool all_f() {
    return Op<T>::value && all_f<Op, Types...>();
}

template <template <typename> class Op, typename T, typename... Types>
struct all_s {
    constexpr static bool value = Op<T>::value && all_s<Op, Types...>::value;
};

template <template <typename> class Op, typename T>
struct all_s<Op, T> {
    constexpr static bool value = Op<T>::value;
};

int
main() {
    std::cout
        << "all_f<std::is_integral, int, short>() = "
        << all_f<std::is_integral, int, short>()
        << std::endl;

    std::cout
        << "all_f<std::is_integral, int, float>() = "
        << all_f<std::is_integral, int, float>()
        << std::endl;

    std::cout
        << "all_s<std::is_integral, int, short>::value = "
        << all_s<std::is_integral, int, short>::value
        << std::endl;

    std::cout
        << "all_s<std::is_integral, int, float>::value = "
        << all_s<std::is_integral, int, float>::value
        << std::endl;

    return 0;
}

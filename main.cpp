#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <string_view>
#include "utils.h"

int main() {
    fmt::println("C++20 Example Program Started");

    Actions::Utils utils("Test Data");
    fmt::println("Data: {}", utils.getData());

    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto even_numbers = numbers | std::views::filter([](int n) { return n % 2 == 0; });

    fmt::print("Even numbers: ");
    for (int n : even_numbers) {
        fmt::print("{} ", n);
    }
    fmt::println("");

    #ifdef _MSC_VER
    std::cout << std::format("MSVC compiler version: {}\n", _MSC_VER);
    #endif

    #ifdef __GNUC__
    fmt::println("GCC compiler version: {}.{}.{}", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
    #endif

    return 0;
}

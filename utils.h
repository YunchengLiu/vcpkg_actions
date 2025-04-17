#pragma once

#include <string>
#include <concepts>
#include <type_traits>

namespace Actions {

// C++20 concept example
template<typename T>
concept Numeric = std::is_arithmetic_v<T>;

class Utils {
public:
    Utils(std::string data);
    
    std::string getData() const;
    void setData(std::string newData);
    
    // C++20 concepts usage example
    template<Numeric T>
    T add(T a, T b) {
        return a + b;
    }
    
private:
    std::string data_;
};

} // namespace Actions

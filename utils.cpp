#include "utils.h"
#include <fmt/core.h>
#include <format>

namespace Actions {

Utils::Utils(std::string data) : data_(std::move(data)) {
    fmt::print("Utils object created, data: {}\n", data_);
    fmt::print("Utils object created, from std::format data: {}\n", std::format("{}", data_));
}

std::string Utils::getData() const {
    return data_;
}

void Utils::setData(std::string newData) {
    data_ = std::move(newData);
}

} // namespace Actions

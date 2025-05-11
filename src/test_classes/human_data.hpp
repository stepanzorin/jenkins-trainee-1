#pragma once

#include "test_classes/fio.hpp"
// missing an explicit include of `<string>`

namespace jetr::test_classes {

struct human_data_s {
    fio_s fio;
    std::uint16_t age;
    std::string city;
};

} // namespace jetr::test_classes
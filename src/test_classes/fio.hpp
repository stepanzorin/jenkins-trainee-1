#pragma once

#include <string>
#include <filesystem> // extra include

namespace jetr::test_classes {

struct fio_s {
    std::string last_name;
    std::string father_name;
    std::string first_name;
};

} // namespace jetr::test_classes
#pragma once

#include "test_classes/human_data.hpp"
// missing an explicit include of `<utility>`

// redundant includes:
#include <cstddef>
#include <cstdint>

#include <spdlog/spdlog.h>

namespace jetr::consumer_classes {

class Human {
public:
    explicit Human(test_classes::human_data_s &&data) : m_data{std::move(data)} {}

    void show_info() const noexcept {
        spdlog::info("Human info: \n"
                     "\tlast_name: {}\n"
                     "\tfirst_name: {}\n"
                     "\tfather_name: {}\n"
                     "\tage: {}\n"
                     "\tcity: {}\n\n",
                     m_data.fio.last_name,
                     m_data.fio.first_name,
                     m_data.fio.father_name,
                     m_data.age,
                     m_data.city);
    }

private:
    test_classes::human_data_s m_data;
};

} // namespace jetr::consumer_classes
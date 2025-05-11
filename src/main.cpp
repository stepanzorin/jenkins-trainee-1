// unused include:
#include <iostream>

#include <spdlog/spdlog.h>

#include "consumer_classes/human.hpp"

int main() {
    // Local variable 'human' can be made const
    auto human = jetr::consumer_classes::Human{
            {.fio = {"Ivanov", "Ivan", "Ivanovich"}, .age = 20, .city = "Moscow"}};

    human.show_info();

    return 0;
}
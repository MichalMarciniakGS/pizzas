#pragma once
#include <string>
#include <tuple>
#include <vector>
#include <chrono>
#include <numeric>
#include <algorithm>
#include <thread>
#include <iostream>
#include "Pizza.hpp"

class PizzaTimeImplOriginal : public PizzaTime {
    public:
    void waitForPizza(Pizza* pizza) override{
        std::this_thread::sleep_for(pizza->getBakingTime());
    };

};
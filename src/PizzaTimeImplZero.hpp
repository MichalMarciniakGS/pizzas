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

class PizzaTimeImplZero : public PizzaTime {
    public:

    void waitForPizza(Pizza* pizza) override{
        // return std::chrono::seconds(5);
    };
};
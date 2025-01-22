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

class PizzaTime{
    public:

    virtual void waitForPizza(Pizza* pizza) = 0;

    virtual ~PizzaTime() {}
};
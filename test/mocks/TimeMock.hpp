#pragma once
#include "PizzaTime.hpp"
#include "gmock/gmock.h"

class TimeMock : public PizzaTime {
    public:
    MOCK_METHOD(void, waitForPizza, (Pizza* pizza), (override));
};
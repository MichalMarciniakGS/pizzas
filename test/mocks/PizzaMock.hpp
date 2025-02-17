#include "Pizza.hpp"
#include "gmock/gmock.h"

// constexpr std::string dummyName = "dummy";

struct PizzaDummy : public Pizza
{
    // PizzaDummy() : Pizza("dummy", 0.0, minutes(0)) {}
    std::string getName() const override { return "dummy"; }
    double getPrice() const override { return 0.0; }
    minutes getBakingTime() const override { return minutes(0); }
};

struct PizzaStub : public Pizza
{
    // PizzaStub(std::string name) : Pizza(name, 0.0, minutes(0)) {}
    std::string getName() const override { return "StubPizza"; }
    double getPrice() const override
    {
        if (getName() == "stub")
            return 0.0;
        else 
            return 10.0;
    }
    minutes getBakingTime() const override { return minutes(1); }
};

struct PizzaMock : public Pizza {

MOCK_METHOD(std::string, getName, (), (const, override));
MOCK_METHOD(double, getPrice, (), (const, override));
MOCK_METHOD(minutes, getBakingTime,(), (const, override));
// MOCK_METHOD(minutes, bakePizzas,(), (const, override));

};


// struct PizzaMock : public Pizza
// {
//     // PizzaMock() : Pizza("mock", 0.0, minutes(0)) {} // constructors should be avoided. Interface is advised
//     MOCK_CONST_METHOD0(getName, std::string());
//     MOCK_CONST_METHOD0(getPrice, double());
//     MOCK_CONST_METHOD0(getBakingTime, minutes());
// };


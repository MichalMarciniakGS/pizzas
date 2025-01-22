#pragma once
#include <list>
#include <set>
#include <chrono>
#include <string>

using minutes = std::chrono::seconds;   // To simulate time flow ;)

class Pizza
{
public:
    virtual ~Pizza() = default;
    virtual std::string getName() const = 0;
    virtual double getPrice() const = 0;
    virtual minutes getBakingTime() const = 0;
};

class ConcretePizza : public Pizza
{
public:
    ConcretePizza() = default;
    ConcretePizza(std::string const & name, double price, minutes bakingTime);
    std::string getName() const override;
    double getPrice() const override;
    minutes getBakingTime() const override;

private:
    std::string name_;
    double price_;
    minutes bakingTime_;
};

using Pizzas = std::set<Pizza*>;

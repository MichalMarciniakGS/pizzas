class PizzaDummmy : public Pizza
{
public:
    std::string Pizza::getName() override
    {
        return "Pizza Italiana"
    }

    minutes Pizza::getBakingTime() override
    {
        return minutes(10);
    }
}
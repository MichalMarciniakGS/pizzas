class PizzaStub : public Pizza
{
    public:

    double Pizza::getPrice() override{
        if (Pizza::getName().contains("stub"))
        {
            return 5;
        }else{
            return 30;
        }
    } 
}
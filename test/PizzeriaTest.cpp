#include <gtest/gtest.h>
#include <string>
#include "mocks/PizzaMock.hpp"
#include "Pizzeria.hpp"
#include "Margherita.hpp"
#include "Funghi.hpp"
#include "PizzaTime.hpp"
#include "PizzaTimeImplZero.hpp"

using namespace std;
using namespace ::testing;

struct PizzeriaTest : public ::testing::Test
{

PizzaTimeImplZero pizzaTimeImplZero;

public:
    Pizzeria pizzeria = Pizzeria("dummyName", &pizzaTimeImplZero); 
};


TEST_F(PizzeriaTest, priceForMargherita25AndFunghi30ShouldBe55)
{
    // Given
    Pizzas pizzas = {new Margherita{25.0}, new Funghi{30.0}};

    // When
    auto orderId = pizzeria.makeOrder(pizzas);
    auto price = pizzeria.calculatePrice(orderId);

    // Then
    ASSERT_EQ(55, price);
}

TEST_F(PizzeriaTest, bakeDummyPizza)
{
    // Given
    Pizzas pizzas = {new PizzaDummy{}};

    // When
    auto orderId = pizzeria.makeOrder(pizzas);
    pizzeria.bakePizzas(orderId);
}

TEST_F(PizzeriaTest, completeOrderWithStubPizza)
{
    // Given
    Pizzas pizzas = {new PizzaStub{}};

    // When
    auto orderId = pizzeria.makeOrder(pizzas);
    pizzeria.bakePizzas(orderId);
    pizzeria.completeOrder(orderId);
}

TEST_F(PizzeriaTest, calculatePriceForPizzaMock)
{   
    // Given
    PizzaMock* mock = new PizzaMock{};
    Pizzas pizzas = {mock};
    EXPECT_CALL(*mock, getPrice()).WillOnce(Return(40.0));
    
    // When
    auto orderId = pizzeria.makeOrder(pizzas);
    auto price = pizzeria.calculatePrice(orderId);

    // Then
    ASSERT_EQ(40, price);

    delete mock;
}

TEST_F(PizzeriaTest, PlayWithMock){

    //Given
    // StrictMock<PizzaMock>* mock = new StrictMock<PizzaMock>{};
    PizzaMock* mock = new PizzaMock{};
    Pizzas pizzas = {mock};
    EXPECT_CALL(*mock,getName).WillOnce(Return("Hawajska"));
    EXPECT_CALL(*mock,getBakingTime);
    
    // EXPECT_CALL(*mock,getBakingTime).WillOnce(Return(minutes(0)));
    
    
    //When
    auto orderId = pizzeria.makeOrder(pizzas);
    pizzeria.bakePizzas(orderId);

    //Then

    //Teardown
    delete mock;

}
TEST_F(PizzeriaTest, GivenNonExistingOrderWhenBakePizzasIsCalledThenInvalidArgumentIsThrown){

    //Given
    constexpr int notExistingOrder = 123;

    //When Then
    
    EXPECT_THROW(pizzeria.bakePizzas(notExistingOrder), std::invalid_argument);
    EXPECT_ANY_THROW(pizzeria.bakePizzas(notExistingOrder));

}
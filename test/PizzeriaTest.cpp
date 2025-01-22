#include <gtest/gtest.h>
#include <string>
#include "mocks/PizzaMock.hpp"
#include "mocks/TimeMock.hpp"
#include "Pizzeria.hpp"
#include "Margherita.hpp"
#include "Funghi.hpp"

using namespace std;
using namespace ::testing;

struct PizzeriaTest : public ::testing::Test
{
    StrictMock<TimeMock> timeMock;
    Pizzeria pizzeria = Pizzeria("testPizzeria", &timeMock);
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
    PizzaDummy* pizza = new PizzaDummy{};
    Pizzas pizzas = {pizza};

    // Expect
    EXPECT_CALL(timeMock, waitForPizza(pizza))
        .Times(1);

    // When
    auto orderId = pizzeria.makeOrder(pizzas);
    pizzeria.bakePizzas(orderId);
}

TEST_F(PizzeriaTest, completeOrderWithStubPizza)
{
    // Given
    PizzaStub* pizza = new PizzaStub{};
    Pizzas pizzas = {pizza};

    // Expect
    EXPECT_CALL(timeMock, waitForPizza(pizza))
        .Times(1);

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

TEST_F(PizzeriaTest, PlayWithMock)
{
    // Given
    PizzaMock* mock = new PizzaMock{};
    Pizzas pizzas = {mock};

    // Expect
    EXPECT_CALL(*mock, getName())
        .WillOnce(Return("Hawajska"));
    EXPECT_CALL(timeMock, waitForPizza(mock))
        .Times(1);
    
    // When
    auto orderId = pizzeria.makeOrder(pizzas);
    pizzeria.bakePizzas(orderId);

    // Cleanup
    delete mock;
}

TEST_F(PizzeriaTest, GivenNonExistingOrderWhenBakePizzasIsCalledThenInvalidArgumentIsThrown)
{
    // Given
    constexpr int notExistingOrder = 123;

    // When Then
    EXPECT_THROW(pizzeria.bakePizzas(notExistingOrder), std::invalid_argument);
    EXPECT_ANY_THROW(pizzeria.bakePizzas(notExistingOrder));
}
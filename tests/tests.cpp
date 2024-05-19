#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "IFactory.h"

class MockFactory : public IFactory {
public:
    MOCK_METHOD(IProductA*, createConcreteProductA, (), (const override));
    MOCK_METHOD(IProductB*, createConcreteProductB, (), (const override));
};

TEST(IFactoryTest, CreateConcreteProductA) {
    auto mockFactory = std::make_shared<MockFactory>();

    EXPECT_CALL(*mockFactory, createConcreteProductA()).WillOnce(Return(nullptr));

    IProductA* productA = mockFactory->createConcreteProductA();

    ASSERT_EQ(productA, nullptr);
}

TEST(IFactoryTest, CreateConcreteProductB) {
    auto mockFactory = std::make_shared<MockFactory>();

    EXPECT_CALL(*mockFactory, createConcreteProductB()).Times(1).WillOnce(Return(nullptr));

    IProductB* productB = mockFactory->createConcreteProductB();

    ASSERT_EQ(productB, nullptr);
}

TEST(IFactoryTest, CreateAllProducts) {
    auto mockFactory = std::make_shared<MockFactory>();

    EXPECT_CALL(*mockFactory, createConcreteProductA()).Times(1);
    EXPECT_CALL(*mockFactory, createConcreteProductB()).Times(1);

    mockFactory->createConcreteProductA();
    mockFactory->createConcreteProductB();
}


#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "IProductA.h"
#include "IProductB.h"
#include "IFactory.h"

class MockFactory : public IFactory {
public:
    MOCK_METHOD(IProductA*, createConcreteProductA, (), (const override));
    MOCK_METHOD(IProductB*, createConcreteProductB, (), (const override));
};

class MockProductA : public IProductA {
public:
    MOCK_METHOD(void, init, (), (const override));
    MOCK_METHOD(void, performTask, (), (const override));
};

TEST(IFactoryTest, CreateConcreteProductA) {
    auto mockFactory = std::make_shared<MockFactory>();

    EXPECT_CALL(*mockFactory, createConcreteProductA()).WillOnce(Return(nullptr));

    IProductA* productA = mockFactory->createConcreteProductA();

    ASSERT_EQ(productA, nullptr);
}

TEST(IFactoryTest, CreateConcreteProductB) {
    auto mockFactory = std::make_shared<MockFactory>();

    EXPECT_CALL(*mockFactory, createConcreteProductB()).WillOnce(Return(nullptr));

    IProductB* productB = mockFactory->createConcreteProductB();

    ASSERT_EQ(productB, nullptr);
}

TEST(IProductATest, InitAndPerformTask) {
    auto mockProductA = std::make_shared<MockProductA>();

    EXPECT_CALL(*mockProductA, init()).Times(1);
    EXPECT_CALL(*mockProductA, performTask()).Times(1);

    mockProductA->init();
    mockProductA->performTask();
}

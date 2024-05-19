cmake_minimum_required(VERSION 3.10)

project(GumballMachine)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCES 
    ConcreteFactoryX.cpp
    ConcreteFactoryY.cpp
    ConcreteProductAX.cpp
    ConcreteProductAY.cpp
    ConcreteProductBX.cpp
    ConcreteProductBY.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(HEADERS
    ConcreteFactoryX.h
    ConcreteFactoryY.h
    ConcreteProductAX.h
    ConcreteProductAY.h
    ConcreteProductBX.h
    ConcreteProductBY.h
    IFactory.h
    IProductA.h
    IProductB.h
)


target_sources(${PROJECT_NAME} PUBLIC ${HEADERS})


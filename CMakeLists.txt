cmake_minimum_required(VERSION 3.0.0)
project(observer VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()

add_library(observer 
            observer.cpp
            concreteObserverA.cpp
            concreteObserverB.cpp)

add_library(subject 
            subject.cpp
            concreteSubject.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(GTest REQUIRED)

add_executable(test_observer test_observer.cpp)

# Tester includes
target_include_directories(
    test_observer
    PUBLIC ${GTEST_INCLUDE_DIRS}
)

# Tester libraries
target_link_libraries(
    test_observer
    subject
    observer
    ${GTEST_LIBRARIES}
)

add_test(NAME test_observer
         COMMAND test_observer)

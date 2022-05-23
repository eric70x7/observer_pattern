// Copyright 2022 Eric Jones

#include "./test_observer.h"
#include <gtest/gtest.h>
#include <iostream>

#include "./subject.h"
#include "./observer.h"
#include "./concreteObserverA.h"
#include "./concreteObserverB.h"

test_observer::test_observer() {
}

test_observer::~test_observer() {
}

TEST(ObserverSuite, single_observer_use_count) {
    subject s;

    std::shared_ptr<observer> a(new concreteObserverA);
    EXPECT_EQ(1, a.use_count());
    s.Attach(a);
    EXPECT_EQ(2, a.use_count());
    s.Attach(a);
    EXPECT_EQ(3, a.use_count());
    s.Notify();
    s.Detach(a);
    EXPECT_EQ(1, a.use_count());
}

TEST(ObserverSuite, multi_observer_update_count) {
    subject s;

    std::shared_ptr<observer> a(new concreteObserverA);
    std::shared_ptr<observer> b(new concreteObserverB);

    EXPECT_EQ(1, a.use_count());
    EXPECT_EQ(1, b.use_count());

    s.Attach(b);
    s.Attach(a);

    EXPECT_EQ(2, a.use_count());
    EXPECT_EQ(2, b.use_count());

    EXPECT_EQ(a->GetUpdateCount(), 0);
    EXPECT_EQ(b->GetUpdateCount(), 0);

    // Notify a and b
    s.Notify();

    EXPECT_EQ(a->GetUpdateCount(), 1);
    EXPECT_EQ(b->GetUpdateCount(), 1);

    s.Attach(a);
    s.Notify();

    EXPECT_EQ(3, a.use_count());
    EXPECT_EQ(2, b.use_count());

    // Notify 2 instances of a and 1 of b
    EXPECT_EQ(a->GetUpdateCount(), 3);
    EXPECT_EQ(b->GetUpdateCount(), 2);

    s.Detach(a);

    EXPECT_EQ(1, a.use_count());
    EXPECT_EQ(2, b.use_count());

    s.Notify();

    // Notify b
    EXPECT_EQ(a->GetUpdateCount(), 3);
    EXPECT_EQ(b->GetUpdateCount(), 3);

    s.Detach(b);

    EXPECT_EQ(1, a.use_count());
    EXPECT_EQ(1, b.use_count());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

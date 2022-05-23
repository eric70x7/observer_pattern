// Copyright 2022 Eric Jones

#include "./test_observer.h"
#include <gtest/gtest.h>
#include <iostream>

#include "./concreteSubject.h"
#include "./observer.h"
#include "./concreteObserverA.h"
#include "./concreteObserverB.h"

test_observer::test_observer() {
}

test_observer::~test_observer() {
}

TEST(ObserverSuite, use_counts) {
    std::shared_ptr<concreteSubject> s(new concreteSubject);
    std::shared_ptr<concreteObserverA> a(new concreteObserverA);
    std::shared_ptr<concreteObserverB> b(new concreteObserverB);

    EXPECT_EQ(1, s.use_count());
    EXPECT_EQ(1, a.use_count());
    EXPECT_EQ(1, b.use_count());

    a->SetSubject(s);
    b->SetSubject(s);

    EXPECT_EQ(3, s.use_count());

    s->Attach(a);
    EXPECT_EQ(2, a.use_count());
    EXPECT_EQ(1, b.use_count());
    s->Attach(b);
    EXPECT_EQ(2, a.use_count());
    EXPECT_EQ(2, b.use_count());
    s->Detach(a);
    EXPECT_EQ(1, a.use_count());
    EXPECT_EQ(2, b.use_count());
    s->Detach(b);
    EXPECT_EQ(1, a.use_count());
    EXPECT_EQ(1, b.use_count());

    a.reset();
    EXPECT_EQ(2, s.use_count());
    b.reset();
    EXPECT_EQ(1, s.use_count());
}

TEST(ObserverSuite, state_propogation) {
    std::shared_ptr<concreteSubject> s(new concreteSubject);
    std::shared_ptr<concreteObserverA> a(new concreteObserverA);
    std::shared_ptr<concreteObserverB> b(new concreteObserverB);

    // Give the concrete observers a reference to the concrete subject
    // so that they can retrieve state information
    a->SetSubject(s);
    b->SetSubject(s);

    // initial state
    s->Attach(a);
    s->Attach(b);
    EXPECT_EQ(a->GetState(), 0);
    EXPECT_EQ(b->GetState(), 0);

    // a and b should be notified
    s->SetState(2);
    EXPECT_EQ(a->GetState(), 2);
    EXPECT_EQ(b->GetState(), 2);

    // detach a, only b should be notified
    s->Detach(a);
    s->SetState(3);
    EXPECT_EQ(a->GetState(), 2);
    EXPECT_EQ(b->GetState(), 3);

    // a and b detached, no notification
    s->Detach(b);
    s->SetState(4);
    EXPECT_EQ(a->GetState(), 2);
    EXPECT_EQ(b->GetState(), 3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

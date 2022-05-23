// Copyright 2022 Eric Jones

#include "./concreteObserverB.h"
#include <iostream>
#include <memory>

concreteObserverB::concreteObserverB(std::shared_ptr<concreteSubject> s) :
    subject(s)
{
}

concreteObserverB::~concreteObserverB() {
}

void concreteObserverB::Update() {
    state = subject->GetState();
}

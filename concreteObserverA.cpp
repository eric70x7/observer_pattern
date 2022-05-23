// Copyright 2022 Eric Jones

#include "./concreteObserverA.h"
#include <iostream>
#include <memory>

concreteObserverA::concreteObserverA(std::shared_ptr<concreteSubject> s) :
    subject(s)
{
}

concreteObserverA::~concreteObserverA() {
}

void concreteObserverA::Update() {
    state = subject->GetState();
}

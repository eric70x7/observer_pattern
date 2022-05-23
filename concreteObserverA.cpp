// Copyright 2022 Eric Jones

#include "./concreteObserverA.h"
#include <iostream>

concreteObserverA::concreteObserverA() {
}

concreteObserverA::~concreteObserverA() {
}

void concreteObserverA::Update() {
    update_count++;
}

// Copyright 2022 Eric Jones

#include "./concreteObserverB.h"
#include <iostream>

concreteObserverB::concreteObserverB() {
}

concreteObserverB::~concreteObserverB() {
}

void concreteObserverB::Update() {
    update_count++;
}

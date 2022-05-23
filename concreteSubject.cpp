// Copyright 2022 Eric Jones

#include "./concreteSubject.h"

concreteSubject::concreteSubject() {
}

concreteSubject::~concreteSubject() {
}

int concreteSubject::GetState() {
    return state;
}

void concreteSubject::SetState(concreteSubjectState state) {
    this->state = state;
    Notify();
}

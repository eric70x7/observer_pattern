// Copyright 2022 Eric Jones

#ifndef CONCRETEOBSERVERA_H_
#define CONCRETEOBSERVERA_H_

#include "./observer.h"

#pragma once

class concreteObserverA : public observer {
 public:
    concreteObserverA();
    ~concreteObserverA();

    void Update() override;

 private:
};

#endif  // CONCRETEOBSERVERA_H_

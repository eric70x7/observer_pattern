// Copyright 2022 Eric Jones

#ifndef CONCRETEOBSERVERB_H_
#define CONCRETEOBSERVERB_H_

#include "./observer.h"

#pragma once

class concreteObserverB : public observer {
 public:
    concreteObserverB();
    ~concreteObserverB();

    void Update() override;

 private:
};

#endif  // CONCRETEOBSERVERB_H_

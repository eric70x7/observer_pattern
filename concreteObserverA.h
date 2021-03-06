// Copyright 2022 Eric Jones

#ifndef CONCRETEOBSERVERA_H_
#define CONCRETEOBSERVERA_H_

#include <memory>
#include "./observer.h"
#include "./concreteSubject.h"

#pragma once

class concreteObserverA : public observer {
 public:
    explicit concreteObserverA(std::shared_ptr<concreteSubject> s);
    ~concreteObserverA();

    void Update() override;

    concreteSubject::concreteSubjectState GetState() {
        return state;
    }

 private:
    std::shared_ptr<concreteSubject> subject;
    concreteSubject::concreteSubjectState state;
};

#endif  // CONCRETEOBSERVERA_H_

// Copyright 2022 Eric Jones

#ifndef CONCRETEOBSERVERB_H_
#define CONCRETEOBSERVERB_H_

#include <memory>
#include "./observer.h"
#include "./concreteSubject.h"

#pragma once

class concreteObserverB : public observer {
 public:
    explicit concreteObserverB(std::shared_ptr<concreteSubject> s);
    ~concreteObserverB();

    void Update() override;

    concreteSubject::concreteSubjectState GetState() {
        return state;
    }

 private:
    std::shared_ptr<concreteSubject> subject;
    concreteSubject::concreteSubjectState state;
};

#endif  // CONCRETEOBSERVERB_H_

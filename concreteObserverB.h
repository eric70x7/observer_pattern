// Copyright 2022 Eric Jones

#ifndef CONCRETEOBSERVERB_H_
#define CONCRETEOBSERVERB_H_

#include <memory>
#include "./observer.h"
#include "./concreteSubject.h"

#pragma once

class concreteObserverB : public observer {
 public:
    concreteObserverB();
    ~concreteObserverB();

    void Update() override;

    concreteSubject::concreteSubjectState GetState() {
        return state;
    }

    void SetSubject(std::shared_ptr<concreteSubject> s) {
        subject = s;
    }

 private:
    std::shared_ptr<concreteSubject> subject = nullptr;
    concreteSubject::concreteSubjectState state;
};

#endif  // CONCRETEOBSERVERB_H_

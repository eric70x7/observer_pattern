// Copyright 2022 Eric Jones

#ifndef CONCRETESUBJECT_H_
#define CONCRETESUBJECT_H_

#include "./subject.h"

#pragma once

class concreteSubject : public subject {
 public:
    concreteSubject();
    ~concreteSubject();

    int GetState();
    void SetState(int state);

    typedef int concreteSubjectState;
 private:
    concreteSubjectState state = 0;
};

#endif  // CONCRETESUBJECT_H_

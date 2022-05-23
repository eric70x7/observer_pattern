// Copyright 2022 Eric Jones

#ifndef OBSERVER_H_
#define OBSERVER_H_

#pragma once

class observer {
 public:
    observer();
    ~observer();

    virtual void Update() = 0;

 protected:
};

#endif  // OBSERVER_H_

// Copyright 2022 Eric Jones

#ifndef OBSERVER_H_
#define OBSERVER_H_

#pragma once

class observer {
 public:
    observer();
    ~observer();

    virtual void Update() = 0;

    int GetUpdateCount() { return update_count; }

 protected:
    int update_count = 0;
};

#endif  // OBSERVER_H_

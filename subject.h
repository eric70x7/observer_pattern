// Copyright 2022 Eric Jones

#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <memory>
#include <vector>

#include "./observer.h"

#pragma once

class subject {
 public:
    subject();
    ~subject();

    void Attach(std::shared_ptr<observer>);
    void Detach(std::shared_ptr<observer>);
    void Notify();

 private:
    std::vector<std::shared_ptr<observer> > observers;
};

#endif  // SUBJECT_H_

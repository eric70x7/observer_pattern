// Copyright 2022 Eric Jones

#include "./subject.h"
#include <algorithm>
#include <iostream>
#include <vector>

subject::subject() {
}

subject::~subject() {
}

void subject::Attach(std::shared_ptr<observer> o) {
    observers.push_back(o);
}

void subject::Detach(std::shared_ptr<observer> o) {
    std::vector<std::shared_ptr<observer> >::iterator itr
        = std::find(observers.begin(), observers.end(), o);

    while (itr != observers.cend()) {
        observers.erase(observers.begin()
                        + std::distance(observers.begin(), itr));
        // look for another ocurrance
        itr = std::find(observers.begin(), observers.end(), o);
    }
}

void subject::Notify() {
    for (auto o : observers) {
        o->Update();
    }
}

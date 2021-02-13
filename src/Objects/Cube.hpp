#pragma once
#include "Object.hpp"

class Cube : public Object {
public:
    using Object::Object;
    void display() override;
};
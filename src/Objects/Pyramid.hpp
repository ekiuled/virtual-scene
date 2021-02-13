#pragma once
#include "Object.hpp"

class Pyramid : public Object {
public:
    using Object::Object;
    void display() override;
};
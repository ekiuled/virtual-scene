#pragma once
#include "../Point.hpp"

class Object {
protected:
    Point center_;
    GLfloat scale_;

public:
    Object(Point const& center, GLfloat scale);
    virtual void display() = 0;
};
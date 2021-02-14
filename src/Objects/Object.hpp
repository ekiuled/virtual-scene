#pragma once
#include "../Point.hpp"

class Object {
protected:
    Point center_;
    GLfloat scale_;
    GLfloat rotation_x_;
    GLfloat rotation_y_;

public:
    Object(Point const& center, GLfloat scale, GLfloat rotation_x, GLfloat rotation_y);
    virtual void display() = 0;
};
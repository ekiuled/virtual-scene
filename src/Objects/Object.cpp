#include "Object.hpp"

Object::Object(Point const& center, GLfloat scale, GLfloat rotation_x, GLfloat rotation_y)
    : center_(center), scale_(scale), rotation_x_(rotation_x), rotation_y_(rotation_y) {
}
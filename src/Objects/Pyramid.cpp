#include "Pyramid.hpp"

void Pyramid::display() {
    glTranslatef(center_.x, center_.y, center_.z);

    glBegin(GL_TRIANGLES);

    // Front
    glVertex3f(0.0, scale_, 0.0);
    glVertex3f(-scale_, -scale_, scale_);
    glVertex3f(scale_, -scale_, scale_);

    // Right
    glVertex3f(0.0, scale_, 0.0);
    glVertex3f(scale_, -scale_, scale_);
    glVertex3f(scale_, -scale_, -scale_);

    // Back
    glVertex3f(0.0, scale_, 0.0);
    glVertex3f(scale_, -scale_, -scale_);
    glVertex3f(-scale_, -scale_, -scale_);

    // Left
    glVertex3f(0.0, scale_, 0.0);
    glVertex3f(-scale_, -scale_, -scale_);
    glVertex3f(-scale_, -scale_, scale_);

    glEnd();
}
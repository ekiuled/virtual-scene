#include "Pyramid.hpp"

void Pyramid::display() {
    glPushMatrix();
    glTranslatef(center_.x, center_.y, center_.z);

    glBegin(GL_TRIANGLES);

    // Front
    glNormal3f(0.0, 1.0, 2.0);
    glVertex3f(0.0, scale_, 0.0);
    glVertex3f(-scale_, -scale_, scale_);
    glVertex3f(scale_, -scale_, scale_);

    // Right
    glNormal3f(2.0, 1.0, 0.0);
    glVertex3f(0.0, scale_, 0.0);
    glVertex3f(scale_, -scale_, scale_);
    glVertex3f(scale_, -scale_, -scale_);

    // Back
    glNormal3f(0.0, 1.0, -2.0);
    glVertex3f(0.0, scale_, 0.0);
    glVertex3f(scale_, -scale_, -scale_);
    glVertex3f(-scale_, -scale_, -scale_);

    // Left
    glNormal3f(-2.0, 1.0, 0.0);
    glVertex3f(0.0, scale_, 0.0);
    glVertex3f(-scale_, -scale_, -scale_);
    glVertex3f(-scale_, -scale_, scale_);

    glEnd();
    glPopMatrix();
}
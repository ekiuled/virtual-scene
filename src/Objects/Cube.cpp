#include "Cube.hpp"

void Cube::display() {
    glPushMatrix();

    glTranslatef(center_.x, center_.y, center_.z);
    glRotatef(rotation_x_, 1.0f, 0.0f, 0.0f);
    glRotatef(rotation_y_, 0.0f, 1.0f, 0.0f);

    glBegin(GL_QUADS);

    // Top face (y = scale_)
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(scale_, scale_, -scale_);
    glVertex3f(-scale_, scale_, -scale_);
    glVertex3f(-scale_, scale_, scale_);
    glVertex3f(scale_, scale_, scale_);

    // Bottom face (y = -scale_)
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(scale_, -scale_, scale_);
    glVertex3f(-scale_, -scale_, scale_);
    glVertex3f(-scale_, -scale_, -scale_);
    glVertex3f(scale_, -scale_, -scale_);

    // Front face  (z = scale_)
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(scale_, scale_, scale_);
    glVertex3f(-scale_, scale_, scale_);
    glVertex3f(-scale_, -scale_, scale_);
    glVertex3f(scale_, -scale_, scale_);

    // Back face (z = -scale_)
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(scale_, -scale_, -scale_);
    glVertex3f(-scale_, -scale_, -scale_);
    glVertex3f(-scale_, scale_, -scale_);
    glVertex3f(scale_, scale_, -scale_);

    // Left face (x = -scale_)
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(-scale_, scale_, scale_);
    glVertex3f(-scale_, scale_, -scale_);
    glVertex3f(-scale_, -scale_, -scale_);
    glVertex3f(-scale_, -scale_, scale_);

    // Right face (x = scale_)
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(scale_, scale_, -scale_);
    glVertex3f(scale_, scale_, scale_);
    glVertex3f(scale_, -scale_, scale_);
    glVertex3f(scale_, -scale_, -scale_);

    glEnd();
    glPopMatrix();
}
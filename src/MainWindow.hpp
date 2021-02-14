#pragma once
#include "Objects/Object.hpp"
#include <GL/glut.h>
#include <memory>

class MainWindow {
    Point camera_;
    std::unique_ptr<Object> cube_;
    std::unique_ptr<Object> pyramid_;
    const GLfloat delta_ = 0.1;

    void init();

public:
    MainWindow(Point const& camera,
               Point const& cube_center,
               GLfloat cube_scale,
               Point const& pyramid_center,
               GLfloat pyramid_scale);

    void resize(int w, int h);
    void display();

    void right();
    void left();
    void up();
    void down();
    void forward();
    void backward();
};
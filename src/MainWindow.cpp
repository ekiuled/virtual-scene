#include "MainWindow.hpp"
#include "Objects/Cube.hpp"
#include "Objects/Pyramid.hpp"
#include <iostream>

MainWindow::MainWindow(Point const& cube_center,
                       GLfloat cube_scale,
                       Point const& pyramid_center,
                       GLfloat pyramid_scale,
                       Point const& camera) {
    cube_ = std::make_unique<Cube>(cube_center, cube_scale);
    pyramid_ = std::make_unique<Pyramid>(pyramid_center, pyramid_scale);
    camera_ = camera;

    {
        int argc = 0;
        glutInit(&argc, nullptr);
    }

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 200);
    glutCreateWindow("Virtual scene");

    init();
}

void MainWindow::init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, // Y FOV
                   1.0,  // aspect ratio
                   1.0,  // zNear
                   200.0 // zFar
    );
}

void MainWindow::resize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void MainWindow::display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    GLfloat light_diffuse[] = {0.6, 0.6, 0.7};
    GLfloat light_position[] = {1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    gluLookAt(camera_.x, camera_.y, camera_.z, // eye
              camera_.x, camera_.y, 0.0,       // center
              0.0, 1.0, 0.0                    // up
    );

    cube_->display();
    pyramid_->display();

    glDisable(GL_LIGHT0);

    glutSwapBuffers();
}

void MainWindow::right() {
    camera_.x += delta_;
}

void MainWindow::left() {
    camera_.x -= delta_;
}

void MainWindow::up() {
    camera_.y += delta_;
}

void MainWindow::down() {
    camera_.y -= delta_;
}
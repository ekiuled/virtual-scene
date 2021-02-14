#include "MainWindow.hpp"
#include <iostream>
#include <stdexcept>

std::unique_ptr<MainWindow> mainWindow;

void display() {
    mainWindow->display();
}

void resize(int w, int h) {
    mainWindow->resize(w, h);
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(30, timer, value);
}

void keyboard(int key, int, int) {
    if (key == GLUT_KEY_RIGHT) {
        mainWindow->right();
    } else if (key == GLUT_KEY_LEFT) {
        mainWindow->left();
    } else if (key == GLUT_KEY_UP) {
        mainWindow->up();
    } else if (key == GLUT_KEY_DOWN) {
        mainWindow->down();
    }
    glutPostRedisplay();
}

GLfloat glfloat(const char* str) {
    return atof(str);
}

void argparse(int argc,
              char** argv,
              Point& camera,
              Point& cube_center,
              GLfloat& cube_scale,
              Point& pyramid_center,
              GLfloat& pyramid_scale) {
    enum {
        camX = 1,
        camY,
        camZ,
        cubeX,
        cubeY,
        cubeZ,
        cubeScale,
        pyramidX,
        pyramidY,
        pyramidZ,
        pyramidScale,
        argsize
    };

    if (argc < argsize) {
        throw std::invalid_argument("Wrong number of arguments");
    }

    camera = {glfloat(argv[camX]), glfloat(argv[camY]), glfloat(argv[camZ])};
    cube_center = {glfloat(argv[cubeX]), glfloat(argv[cubeY]), glfloat(argv[cubeZ])};
    cube_scale = glfloat(argv[cubeScale]);
    pyramid_center = {glfloat(argv[pyramidX]), glfloat(argv[pyramidY]),
                      glfloat(argv[pyramidZ])};
    pyramid_scale = glfloat(argv[pyramidScale]);
}

int main(int argc, char** argv) {
    Point camera;
    Point cube_center;
    GLfloat cube_scale;
    Point pyramid_center;
    GLfloat pyramid_scale;

    argparse(argc, argv, camera, cube_center, cube_scale, pyramid_center, pyramid_scale);

    mainWindow = std::make_unique<MainWindow>(camera, cube_center, cube_scale,
                                              pyramid_center, pyramid_scale);

    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutTimerFunc(0, timer, 0);
    glutSpecialFunc(keyboard);
    glutMainLoop();

    return 0;
}
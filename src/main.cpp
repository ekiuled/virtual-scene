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

void special(int key, int, int) {
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

void keyboard(unsigned char key, int, int) {
    if (key == 'd') {
        mainWindow->right();
    } else if (key == 'a') {
        mainWindow->left();
    } else if (key == 'w') {
        mainWindow->up();
    } else if (key == 's') {
        mainWindow->down();
    } else if (key == 'e') {
        mainWindow->forward();
    } else if (key == 'q') {
        mainWindow->backward();
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
              GLfloat& cube_rotation_x,
              GLfloat& cube_rotation_y,
              Point& pyramid_center,
              GLfloat& pyramid_scale,
              GLfloat& pyramid_rotation_x,
              GLfloat& pyramid_rotation_y) {
    enum {
        camX = 1,
        camY,
        camZ,
        cubeX,
        cubeY,
        cubeZ,
        cubeScale,
        cubeRotX,
        cubeRotY,
        pyramidX,
        pyramidY,
        pyramidZ,
        pyramidScale,
        pyramidRotX,
        pyramidRotY,
        argsize
    };

    if (argc < argsize) {
        throw std::invalid_argument("Wrong number of arguments");
    }

    camera = {glfloat(argv[camX]), glfloat(argv[camY]), glfloat(argv[camZ])};
    cube_center = {glfloat(argv[cubeX]), glfloat(argv[cubeY]), glfloat(argv[cubeZ])};
    cube_scale = glfloat(argv[cubeScale]);
    cube_rotation_x = glfloat(argv[cubeRotX]);
    cube_rotation_y = glfloat(argv[cubeRotY]);
    pyramid_center = {glfloat(argv[pyramidX]), glfloat(argv[pyramidY]),
                      glfloat(argv[pyramidZ])};
    pyramid_scale = glfloat(argv[pyramidScale]);
    pyramid_rotation_x = glfloat(argv[pyramidRotX]);
    pyramid_rotation_y = glfloat(argv[pyramidRotY]);
}

int main(int argc, char** argv) {
    Point camera;
    Point cube_center;
    GLfloat cube_scale, cube_rotation_x, cube_rotation_y;
    Point pyramid_center;
    GLfloat pyramid_scale, pyramid_rotation_x, pyramid_rotation_y;

    argparse(argc, argv, camera, cube_center, cube_scale, cube_rotation_x, cube_rotation_y,
             pyramid_center, pyramid_scale, pyramid_rotation_x, pyramid_rotation_y);

    mainWindow = std::make_unique<MainWindow>(
        camera, cube_center, cube_scale, cube_rotation_x, cube_rotation_y,
        pyramid_center, pyramid_scale, pyramid_rotation_x, pyramid_rotation_y);

    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutTimerFunc(0, timer, 0);
    glutSpecialFunc(special);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
#include "MainWindow.hpp"

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

int main(int argc, char** argv) {
    Point cube_center{1.0, 1.0, -1.0};
    GLfloat cube_scale = 0.5;
    Point pyramid_center{-1.5, 0.0, -3.0};
    GLfloat pyramid_scale = 1.0;
    Point camera{0.0, 0.0, 4.0};

    mainWindow = std::make_unique<MainWindow>(
        cube_center, cube_scale, pyramid_center, pyramid_scale, camera);

    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutTimerFunc(0, timer, 0);
    glutSpecialFunc(keyboard);
    glutMainLoop();

    return 0;
}
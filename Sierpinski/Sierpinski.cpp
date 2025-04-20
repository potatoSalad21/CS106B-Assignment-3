#include <cmath>
#include <iostream>
#include "StanfordCPPLib/gwindow.h"
#include "StanfordCPPLib/simpio.h"
using namespace std;

// constant variables
const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;

// function declarations
double getSideLength();
int getFractalOrder();
void drawFractal(GWindow&, double, int);
void drawTriangles(GWindow&, double, double, double, int);

int main() {
    double sideLen = getSideLength();
    int fractalOrder = getFractalOrder();
    GWindow win(WIN_WIDTH, WIN_HEIGHT);
    drawFractal(win, sideLen, fractalOrder);

    return 0;
}

// main function for drawing the whole thing
void drawFractal(GWindow &win, double sideLen, int fractalOrder) {
    double height = sideLen * sqrt(3) / 2.0; // math formula for getting height
    double triangleX = win.getWidth() / 2.0;
    double triangleY = (win.getHeight() - height) / 2.0;

    // draw first triangle
    win.drawPolarLine(triangleX, triangleY, sideLen, 300);
    GPoint pnt = win.drawPolarLine(triangleX, triangleY, sideLen, 240);
    win.drawPolarLine(pnt.getX(), pnt.getY(), sideLen, 0);

    drawTriangles(win, triangleX, triangleY, sideLen / 2, fractalOrder);
}

// draws triangles recursively
void drawTriangles(GWindow &win, double x, double y, double sideLen, int order) {
    if (order == 0) return; // base-case

    double prevHeight = sideLen * sqrt(3);
    win.drawPolarLine(x, y + prevHeight, sideLen, 120);
    GPoint pnt = win.drawPolarLine(x, y + prevHeight, sideLen, 60);
    win.drawPolarLine(pnt.getX(), pnt.getY(), sideLen, 180);

    // draw next three triangles
    double halfSideLen = sideLen / 2.0;
    drawTriangles(win, x, y, halfSideLen, order - 1);
    drawTriangles(win, x - halfSideLen, y + prevHeight / 2.0, halfSideLen, order - 1);
    drawTriangles(win, x + halfSideLen, y + prevHeight / 2.0, halfSideLen, order - 1);
}

/* helper functions */

double getSideLength() {
    while (true) {
        double len = getReal("Enter the length of the triangle side: ");
        if (len > 0) return len;
        cout << "ERROR: length can't be negative or zero";
    }
}

int getFractalOrder() {
    while (true) {
        int order = getInteger("Enter the fractal order: ");
        if (order >= 0) return order;
        cout << "ERROR: fractal order can't be negative";
    }
}

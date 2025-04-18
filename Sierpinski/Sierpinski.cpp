#include <cmath>
#include <iostream>
#include "StanfordCPPLib/gwindow.h"
#include "StanfordCPPLib/simpio.h"
using namespace std;

constexpr int WIN_WIDTH = 800;
constexpr int WIN_HEIGHT = 600;

double getSideLength();
int getFractalOrder();
void drawFractal(GWindow&, double, int);

int main() {
    double sideLen = getSideLength();
    int fractalOrder = getFractalOrder();
    GWindow win(WIN_WIDTH, WIN_HEIGHT);
    drawFractal(win, sideLen, fractalOrder);

    return 0;
}

void drawFractal(GWindow &win, double sideLen, int fractalOrder) {
    double height = sideLen * sqrt(3) / 2.0; // math formula for getting height
    double triangleX = win.getWidth() / 2.0;
    double triangleY = (win.getHeight() - height) / 2.0;
    // TODO draw recursively
}

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

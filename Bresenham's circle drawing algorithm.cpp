#include <iostream>
#include <graphics.h> // Include graphics library (like graphics.h in Turbo C++)

void plotCirclePoints(int xCenter, int yCenter, int x, int y) {
    putpixel(xCenter + x, yCenter + y, WHITE);
    putpixel(xCenter - x, yCenter + y, WHITE);
    putpixel(xCenter + x, yCenter - y, WHITE);
    putpixel(xCenter - x, yCenter - y, WHITE);
    putpixel(xCenter + y, yCenter + x, WHITE);
    putpixel(xCenter - y, yCenter + x, WHITE);
    putpixel(xCenter + y, yCenter - x, WHITE);
    putpixel(xCenter - y, yCenter - x, WHITE);
}

void drawCircle(int xCenter, int yCenter, int radius) {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius; // Initial decision parameter

    // Draw the initial points
    plotCirclePoints(xCenter, yCenter, x, y);

    while (x < y) {
        x++;
        if (d < 0) {
            d = d + 4 * x + 6; // Decision parameter
        } else {
            y--;
            d = d + 4 * (x - y) + 10; // Decision parameter
        }
        plotCirclePoints(xCenter, yCenter, x, y);
    }
}

int main() {
    int gd = DETECT, gm;

    // Initialize the graphics mode
    initgraph(&gd, &gm, "");

    int xCenter = 200; // Center X
    int yCenter = 200; // Center Y
    int radius = 100;  // Radius of the circle

    drawCircle(xCenter, yCenter, radius);

    getch(); // Wait for a key press
    closegraph(); // Close the graphics mode
    return 0;
}

#include "Images.h"

void Image2(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);
    POINT p[6] = {
        cx - 20,    cy - 20,
        cx,	        cy,
        cx + 20,   	cy - 20,
        cx + 20,  	cy + 20,
        cx - 20,  	cy + 20,
        cx - 20,  	cy - 20,

    };
    Polyline(hdc, p, 6);
    DeleteObject(hPen);
}
void Image6(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[10];
    p[0].x = cx;
    p[0].y = cy;
    p[1].x = cx;
    p[1].y = cy + 10;
    p[2].x = cx + 10;
    p[2].y = cy + 10;
    p[3].x = cx + 10;
    p[3].y = cy - 10;
    p[4].x = cx - 10;
    p[4].y = cy - 10;
    p[5].x = cx - 10;
    p[5].y = cy + 20;
    p[6].x = cx + 20;
    p[6].y = cy + 20;
    p[7].x = cx + 20;
    p[7].y = cy - 20;
    p[8].x = cx - 20;
    p[8].y = cy - 20;
    p[9].x = cx - 20;
    p[9].y = cy + 20;

    Polyline(hdc, p, 10);
    DeleteObject(hPen);
}
void Image3(HDC hdc, int cx, int cy, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, color);
    SelectObject(hdc, hPen);

    POINT p[5];
    p[0].x = cx - 20;
    p[0].y = cy - 20;
    p[1].x = cx;
    p[1].y = cy;
    p[2].x = cx + 20;
    p[2].y = cy - 20;
    p[3].x = cx;
    p[3].y = cy + 20;
    p[4].x = cx - 20;
    p[4].y = cy - 20;

    Polyline(hdc, p, 5);
    DeleteObject(hPen);
}
void drawTruck(HDC hdc, int x, int y, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);
    Rectangle(hdc, 50 + x, 50 + y, 100 + x, 75 + y);
    Rectangle(hdc, 25 + x, 75 + y, 100 + x, 100 + y);
    Rectangle(hdc, 100 + x, 25 + y, 175 + x, 100 + y);
    hPen = CreatePen(PS_SOLID, 3, RGB(200, 0, 0));
    SelectObject(hdc, hPen);
    Ellipse(hdc, 50 + x, 82 + y, 75 + x, 112 + y);
    Ellipse(hdc, 125 + x, 82 + y, 150 + x, 112 + y);
}
void gg(HDC hdc, int x, int y, COLORREF color) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, color);
    SelectObject(hdc, hPen);
    Rectangle(hdc, 50 + x, 50 + y, 200 + x, 100 + y);
    Rectangle(hdc, 75 + x, 100 + y, 175 + x, 150 + y);
    Rectangle(hdc, 100 + x, 150 + y, 150 + x, 200 + y);

    hPen = CreatePen(PS_SOLID, 3, RGB(200, 0, 0));
    SelectObject(hdc, hPen);
    Rectangle(hdc, 50 + x, 99 + y, 200 + x, 100 + y);
}
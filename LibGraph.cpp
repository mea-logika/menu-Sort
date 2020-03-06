#include "TXLib.h"
#include "math.h"

const double pi = 3.14159265358979323846;

//-------------------------------------------------------------------------------------------
struct TPoint
    {
    double x, y;
    };
struct TPointPolar
    {
     double R, Alpha;
    };
struct TPixelGraph
    {
    TPoint Pixel_;                               // Точка на графике в математических координатах
    COLORREF Color_;                             // Цвет точки на графике
    double Size_;                                // Размер точки на графике

    };
struct TOsnova
    {
    TPoint PWin1_, PWin2_ ;                      // Точки, определяющие геометрию окна
    TPoint PMath1_, PMath2_;                     // Точки, определяющие геометрию на графике
    TPoint CenterWin, CenterMath;                // Центр математический и соотвествующая точка пересчета.
    COLORREF ColorFon_, ColorXY_, ColorSetka_,   // Цветовые характеристики
             ColorText_;
    double Turn;                                 // Угол поворота

    void Draw();                                 // Метод для отображения в окне


    };

double DecartToPolar (TPoint A,TPoint Centr = {0, 0});
//TPoint PolarToDecart (TPointPolar A, Centr);

//-------------------------------------------------------------------------------------------

int main ()
    {
    $unittest(DecartToPolar({5, 5}, {0, 0}), 45);
    $unittest(DecartToPolar({-5, 5}, {0, 0}), 135);
    $unittest(DecartToPolar({5, -5}, {0, 0}), -45);
    $unittest(DecartToPolar({-5, -5}, {0, 0}), 45+180);
    $unittest(DecartToPolar({0, 5}, {0, 0}), 90);



    //TPointPolar A = DecartToPolar({-5, 5}, {0, 0});
    //$(A.R);
    //$(A.Alpha);

    };

//-------------------------------------------------------------------------------------------
double DecartToPolar (TPoint A, TPoint Centr)
    {

    TPointPolar B;
    double dx = A.x - Centr.x;
    double dy = A.y - Centr.y;

    B.R = sqrt(dx * dx - dy * dy);

    if (dx != 0) B.Alpha = atan (dy / dx);
    else B.Alpha = pi / 2;
    if (A.x<0) B.Alpha += pi;
    double degr = B.Alpha / pi * 180;
    //$(degr);
    return degr;
    }


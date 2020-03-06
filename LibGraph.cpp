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
    TPoint Pixel_;                               // ����� �� ������� � �������������� �����������
    COLORREF Color_;                             // ���� ����� �� �������
    double Size_;                                // ������ ����� �� �������

    };
struct TOsnova
    {
    TPoint PWin1_, PWin2_ ;                      // �����, ������������ ��������� ����
    TPoint PMath1_, PMath2_;                     // �����, ������������ ��������� �� �������
    TPoint CenterWin, CenterMath;                // ����� �������������� � �������������� ����� ���������.
    COLORREF ColorFon_, ColorXY_, ColorSetka_,   // �������� ��������������
             ColorText_;
    double Turn;                                 // ���� ��������

    void Draw();                                 // ����� ��� ����������� � ����


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


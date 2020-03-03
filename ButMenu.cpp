#include "TXLib.h"

struct TPoint
    {
    double x, y;
    };

const int Size = 20;
int data[Size];

//typedef int (*TSort) (int data[], int MaxCount);
const int RandomFill = 1;
const int SortFill = 2;
const int BackSortFill = 3;
const int LimitRandom = 4;

int random (int down, int up);


struct TBoxMenu
    {
     char* Title_;
     void (*Sort_) (int MaxCount, int* CoutSwap, int* CountCompare);

     TPoint Pos_, Size_;
     bool Enable_;
     bool Down_;
     COLORREF Color_;
     void Init ();
     void Draw ();

     //TSort Sort_;
     //
//     int (*Sort_) (int data[1000], int MaxCount);

     };

void WhearMouseDown();
bool MouseInRect(TPoint A, TPoint W);

void BubbleSort (int MaxCount, int* CountSwap, int* CountCompare);
void SelectSort (int MaxCount, int* CountSwap, int* CountCompare);
void QuickSort  (int MaxCount, int* CountSwap, int* CountCompare);
void FillArray (int MaxCount, int TypeFill);
void DrawMass (double x1, double y1, double x2, double y2, int MaxCount);

int main ()
    {
    txCreateWindow (800, 600);

    const int MenuBoxs=3;
    TBoxMenu Menu[MenuBoxs] = {{"BubbleSort", &BubbleSort},
                               {"SelectSort", &SelectSort},
                               {"QuickSort",  &QuickSort},
                               {}
                               };
    int i = 0;
    while ( Menu[i].T)
        {
        Menu[i].Pos_.x = 20;
        Menu[i].Size_.x = 200;
        Menu[i].Size_.y = 30;
        Menu[i].Pos_.y = 20 + i * ( Menu[i].Size_.y +4);
        Menu[i].Enable_ = true;
        Menu[i].Down_ = false;
        Menu[i].Color_ = RGB(0, 100, 150);
        Menu[i].Draw();; i++
        }

    WhearMouseDown (Menu, MenuBoxs);

    return 0;
    }

void TBoxMenu::Draw ()
    {
    txSetFillColor(Color_);
    txSetColor(Color_);
    txRectangle(Pos_.x, Pos_.y, Pos_.x+Size_.x, Pos_.y+Size_.y);
    txSetColor(TX_WHITE);
    txTextOut (Pos_.x+5, Pos_.y+5, Title_);
    return ;
    }

void WhearMouseDown (TBoxMenu Menu[], int MenuBoxs)
    {
    while (!txGetAsyncKeyState (VK_ESCAPE))
        {

        for (int i=0; i<MenuBoxs; i++)
            {
            bool LeftDown = (txMouseButtons() == 1 );

            if ( MouseInRect(Menu[i].Pos_, Menu[i].Size_) && LeftDown)
                {
                //FillArray(Size, SortFill);

                FillArray(Size, RandomFill);
                DrawMass (400, 100, 750, 500, Size);
                //Menu[i].Sort_(20, RandomFill);

                }
            }
        }
    return ;
    }
bool MouseInRect(TPoint A, TPoint W)
    {
    bool vert = (txMouseX() >= A.x) && (txMouseX() <= A.x+W.x);
    bool gor = (txMouseY() >= A.y) && (txMouseY() <= A.y+W.y);

    return vert && gor;
    }

void BubbleSort(int MaxCount, int* CoutSwap, int* CountCompare)
    {

    for (int Bubble = 0; Bubble < MaxCount -1; Bubble++)
        for (int pars =0; pars < MaxCount - Bubble -1; pars++)
            {
            if (data [pars] > data [pars+1])
                {
                int lev = data [pars];
                data [pars] = data [pars+1];
                data [pars+1] = lev;
                }
            }
     return ;
     }

void SelectSort(int MaxCount, int* CountSwap, int* CountCompare)
    {

    txSetColor(TX_BLACK);
    txRectangle(300, 300,500, 400);
    txSetColor(TX_WHITE);
    //char s[100] = "";
    //sprintf(s, "Это %s %d", Menu[t].Title_ ,t);
    //txTextOut (300, 300, s);
    return ;
    }
void QuickSort(int MaxCount, int* CountSwap, int* CountCompare)
    {
    txSetColor(TX_BLACK);
    txRectangle(300, 300,500, 400);
    txSetColor(TX_WHITE);
    //char s[100] = "";
    //sprintf(s, "Это %s %d", Menu[t].Title_ ,t);
    //txTextOut (300, 300, s);
    return ;
    }
void FillArray ( int MaxCount, int TypeFill)
    {
    for (int i = 0; i<MaxCount; i++)
        {
        assert ( 0 <= i && i<MaxCount);
        if (TypeFill == RandomFill)   data [i] = random(0, MaxCount);
        if (TypeFill == SortFill)     data [i] = i;
        if (TypeFill == LimitRandom)  data [i] = random (0, 10);
        if (TypeFill == BackSortFill) data [i] = MaxCount - i;
        }

     return ;
    }
void DrawMass (double x1, double y1, double x2, double y2, int MaxCount)
    {
    txSetColor(RGB(20, 20, 20));
    txSetFillColor(RGB(20, 20, 20));
    //txRectangle (x1, y1, x2, y2);

    txSetColor(TX_YELLOW);
    txSetFillColor(TX_YELLOW);

    double dx = (x2 - x1) / (MaxCount+1);
    for (int i = 0; i < MaxCount; i++)
        {
         assert ((i< MaxCount) && (i>=0));
         txCircle (x1 +dx+ dx * i, y2 - data[i]*10, 3);

        }

    return ;
    }

int random (int down, int up)
    {
    return  rand() % (up-down+1)+down;
    }

void Swaps (int* a, int* b)
    {
    int lev = *a;
    *a = *b;
    *b = lev;
    }

#include "TXLib.h"

struct TPoint
    {
    double x, y;
    };

struct TItem
    {
     char* Title_;
     //void (*Sort_) (int MaxCount, int* CountSwap, int* CountCompare);
     void (*Sort_) (int Menu[], int Left, int Right, int* CountSwap, int* CountCompare);
     TPoint Pos_;

     bool Enable_;
     bool Down_;
     };

struct TMenu
    {
    double x0_, y0_, BoxW_, BoxH_;              // Левый верхний угол и размер коробки
    double dx_, dy_;                            // Зазор между коробками
    COLORREF ColBox_, ColLine_, ColText_;       // Цвета коробок

    int MaxBox_ ;                               // Количество коробок
    TItem Item_[10];                         // Характеристики коробок  Максимум???????

    void Init_();                               // Инициализация вычислительных параметров
    void Draw_();                               // Отрисовка меню
    int WhearMouseDown_();

    // ???????????? Нужен typedef - стандарт для общего меню
    // ?????     typedef int (*TSort) (int data[], int MaxCount);
    } ;

//void Init (TBoxMenu Menu[], int MenuBoxs);
bool MouseInRect(TPoint A, int dx, int dy);


int main ()
    {

    txCreateWindow (800, 600);
    TMenu MenuSort = {20, 20, 150, 40, 0, 50, TX_BLUE, TX_YELLOW, TX_WHITE,
                           3, {{"BubbleSort", &BubbleSort},
                               {"SelectSort", &SelectSort},
                               {"QuickSort",  &QuickSort}
                              }
                     };

    MenuSort.Init_();
    MenuSort.Draw_();




    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        int t = MenuSort.WhearMouseDown_();

        if ( t != -1)
            {
           // Item_[t].Sort_(20, RandomFill);
            /*
            txRectangle(500, 300, 700, 700);
            char s[100] = "";
            sprintf(s, "Это %s %d", MenuSort.Item_[t].Title_ ,t);
            txTextOut (500, 300, s);
            */
            }

        }



    return 0;
    }

void TMenu::Init_ ()
    {

    for (int i = 0; i < MaxBox_ ; i++ )
        {
        Item_[i].Pos_.x = x0_ + i * dx_;
        Item_[i].Pos_.y = y0_ + i * dy_;

        Item_[i].Enable_ = true;
        Item_[i].Down_ = false;
        }
    }

void TMenu::Draw_ ()
    {
    for (int i = 0; i < MaxBox_; i++)
        {
        int x0 = Item_[i].Pos_.x;
        int y0 = Item_[i].Pos_.y;
        int x1 = Item_[i].Pos_.x + BoxW_;
        int y1 = Item_[i].Pos_.y + BoxH_;

        txSetFillColor(ColBox_);
        txSetColor(ColLine_);
        txRectangle(x0, y0, x1, y1);
        txSetColor(ColText_);
        txTextOut (x0+5, y0+5, Item_[i].Title_);
        };

     // не реализовано вычисление местоположения текста
    return ;
    }


int TMenu::WhearMouseDown_ ()
    {
    for (int i = 0; i < MaxBox_; i++)
        {
        bool LeftDown = (txMouseButtons() == 1);
        if ( MouseInRect(Item_[i].Pos_, BoxW_, BoxH_) && LeftDown) return i;
        }
    return -1;
    };


bool MouseInRect(TPoint A, int dx, int dy)
    {
    bool vert = (txMouseX() >= A.x) && (txMouseX() <= A.x+dx);
    bool gor = (txMouseY() >= A.y) && (txMouseY() <= A.y+dy);

    return vert && gor;
    }

void BubbleSort(int Menu[], int MaxCount, int* CountSwap, int* CountCompare)
    {
    /*txSetColor(TX_BLACK);
    txRectangle(300, 300,500, 400);
    txSetColor(TX_WHITE);
    char s[100] = "";
    sprintf(s, "Это %s %d", Menu[t].Title_ ,t);
    txTextOut (300, 300, s);
    */
    return ;
     }

void SelectSort(int Menu[], int MaxCount, int* CountSwap, int* CountCompare)
    {
    /*txSetColor(TX_BLACK);
    txRectangle(300, 300,500, 400);
    txSetColor(TX_WHITE);
    char s[100] = "";
    sprintf(s, "Это %s %d", Menu[t].Title_ ,t);
    txTextOut (300, 300, s);
    */

    return ;
    }
void QuickSort(int Menu[], int MaxCount, int* CountSwap, int* CountCompare)
    {
    /*txSetColor(TX_BLACK);
    txRectangle(300, 300,500, 400);
    txSetColor(TX_WHITE);
    char s[100] = "";
    sprintf(s, "Это %s %d", Menu[t].Title_ ,t);
    txTextOut (300, 300, s);
    */

    return ;
    }

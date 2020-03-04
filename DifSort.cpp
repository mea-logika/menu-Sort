#include "TXLib.h"


//const int Size=20;
//int data[Size];

const int RandomFill = 1;
const int SortFill = 2;
const int BackSortFill = 3;
const int LimitRandom = 4;

void FillArray  (int data[], int Left, int Right, int TypeFill);
void BubbleSortSlow (int data[], int Left, int Right, int* CountSwap, int* CountCompare);
void BubbleSort (int data[], int Left, int Right, int* CountSwap, int* CountCompare);

void SelectSort (int data[], int Left, int Right, int* CountSwap, int* CountCompare);
void QuickSort  (int data[], int Left, int Right, int* CountSwap, int* CountCompare);

int random (int down, int up);
void Swaps (int* a, int* b);

int main()
    {
    const int MaxCount = 10;
    int data[MaxCount] = {};
    int CountCompare = 0, CountSwap = 0;

    FillArray(data, 0, MaxCount-1, RandomFill);

    $(data);
    //BubbleSort(data, 0, MaxCount - 1, &CountSwap, &CountCompare);
    //BubbleSortSlow(data, 0, MaxCount - 1, &CountSwap, &CountCompare);
    //SelectSort(data, 0, MaxCount-1, &CountSwap, &CountCompare);
    QuickSort (data, 0, MaxCount-1, &CountSwap, &CountCompare);
    $(data);
    //SelectSort(10);
    $(CountSwap);
    $(CountCompare);

    return 0;
    }

//------------------------------------------------------------------------------------
void BubbleSortSlow(int data[], int Left, int Right, int* CountSwap, int* CountCompare)
    {

    for (int i = 0; i <= Right - Left-1; i++)
        {
        for (int j = Left; j <= Right - i -1; j++)
            {
            *CountCompare = *CountCompare + 1;
            if (data [j] > data [j+1])
                {
                Swaps (&data [j], &data [j+1]);
                *CountSwap = *CountSwap + 1;
                }
            }
        }
     return;
     }

//------------------------------------------------------------------------------------
void BubbleSort(int data[], int Left, int Right, int* CountSwap, int* CountCompare)
    {

    for (int i = 0; i <= Right - Left-1; i++)
        {
        bool IsReady = true;
        for (int j = Left; j <= Right - i -1; j++)
            {

            *CountCompare = *CountCompare + 1;
            if (data [j] > data [j+1])
                {
                Swaps (&data [j], &data [j+1]);
                *CountSwap = *CountSwap + 1;
                IsReady = false;
                }
            }
        if ( IsReady ) break;
        }
     return;
     }

//------------------------------------------------------------------------------------
void SelectSort (int data[], int Left, int Right, int* CountSwap, int* CountCompare)
    {

    for (int i = Left; i < Right; i++)
        {
        int NumberMin = i;
        for (int j = i+1; j <= Right; j++)
            {
            if (data [j] < data [NumberMin])
                {
                NumberMin = j;
                }
            }
        Swaps (&data [i], &data [NumberMin]);

        }

    return ;

    }

//------------------------------------------------------------------------------------
void QuickSort (int data[], int Left, int Right, int* CountSwap, int* CountCompare)
    {
    if (Left < Right)
        {
        *CountCompare = *CountCompare +1;

        int x = random (Left, Right);
        int razd = Left;

        Swaps(&data[x], &data[razd]);
        *CountSwap = *CountSwap +1;

        for (int i = Left+1; i<=Right ; i++)
            {
            if (data [i] < data [razd])
                {
                *CountCompare = *CountCompare +1;

                Swaps(&data[i],    &data[razd+1]);
                Swaps(&data[razd], &data[razd+1]);
                *CountSwap = *CountSwap + 2;

                razd++;
                }
            }
        QuickSort(data, Left,   razd-1, CountSwap, CountCompare);
        QuickSort(data, razd+1, Right,  CountSwap, CountCompare);

        }

    }
//------------------------------------------------------------------------------------

void FillArray ( int data[], int Left, int Right, int TypeFill)
    {
    for (int i = Left; i<= Right; i++)
        {
        //assert ( 0 <= i && i< MaxCount);
        if (TypeFill == RandomFill)   data [i] = random(10, 20); //(1, MaxCount);
        if (TypeFill == SortFill)     data [i] = i;
        if (TypeFill == LimitRandom)  data [i] = random (0, 10);
        if (TypeFill == BackSortFill) data [i] = Right - i;
        }

     return ;
    }



/*
void QuickSort (int left, int right)
    {

    if (left < right)
        {
        int x = random (left, right);
        int razd = (left+right) % 2;
        Swaps(&data[razd], &data[x]);
        int l = left, r = right;
        while (l<r)
            {
            while (data[l] < data[razd]) l++;
            while (data[r] > data[razd]) r--;
            if (l<r)
                {
                Swaps (&data[l], &data[r]);
                l++;
                r--;
                }
            }
        QuickSort(left, razd-1);
        QuickSort(razd+1, right);
        }

    return;
    }

*/







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

#include "TXLib.h"


//const int Size=20;
//int data[Size];

const int RandomFill = 1;
const int SortFill = 2;
const int BackSortFill = 3;
const int LimitRandom = 4;

void FillArray  (int data[], int Left, int Right, int TypeFill);
void BubbleSort (int data[], int Left, int Right, int* CountSwap, int* CountCompare);
void SelectSort (int data[], int Left, int Right, int* CountSwap, int* CountCompare);
void QuickSort  (int data[], int Left, int Right, int* CountSwap, int* CountCompare);

int random (int down, int up);
void Swaps (int* a, int* b);

int main()
    {
    const int MaxCount = 20;
    int data[MaxCount] = {};
    int CountCompare = 0, CountSwap = 0;
    FillArray(data, 0, MaxCount-1, BackSortFill);

    $(data);
    BubbleSort(data, 0, MaxCount - 1, &CountSwap, &CountCompare);
    //SelectSort(10);
    $(data);

    //QuickSort(0, Size-1);
    //$(data);
    return 0;
    }


void BubbleSort(int data[], int Left, int Right, int* CountSwap, int* CountCompare)
    {

    for (int i = 0; i <= Right - Left-1; i++)
        {
        for (int j = Left; j <= Right - i -1; j++)
            {
            if (data [j] > data [j+1])
                {
                Swaps (&data [j], &data [j+1]);

                }
            }
        }
     return;
     }
void SelectSort (int data[], int Left, int Right, int* CountSwap, int* CountCompare)
    {
    /*
    for (int first = 0; first < MaxCount -1; first++)
        {
        int number = first;
        for (int Kand = first; Kand < MaxCount; Kand++)
            {
            if (data [Kand] < data [number])
                {
                number = Kand;
                }
            }
        Swaps (&data [first], &data [number]);

        }

    return ;
    */
    }

void QuickSort (int data[], int Left, int Right, int* CountSwap, int* CountCompare)
    {
    /*
    if (left < right)
        {
        int x = random (left, right);
        int razd = left;
        Swaps(&data[x], &data[razd]);
        for (int i = left+1; i<=right ; i++)
            {
            if (data [i] < data [razd])
                {
                Swaps(&data[i],    &data[razd+1]);
                Swaps(&data[razd], &data[razd+1]);
                razd++;
                }
            }
        QuickSort(left, razd-1);
        QuickSort(razd+1, right);

        }
    */
    }

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

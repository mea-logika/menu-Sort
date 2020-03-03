#include "TXLib.h"


const int Size=20;
int data[Size];

const int RandomFill = 1;
const int SortFill = 2;
const int BackSortFill = 3;
const int LimitRandom = 4;

void FillArray (int MaxCount, int TypeFill);
void BubbleSort(int MaxCount);
void SelectSort(int MaxCount);
void QuickSort (int left, int right);
void QuickSort (int left, int right);

int random (int down, int up);
void Swaps (int* a, int* b);

int main()
    {
    FillArray(Size, BackSortFill);
    $(data);
    //BubbleSort(10);
    //SelectSort(10);
    //QuickSort(0, Size-1);
    $(data);
    return 0;
    }


void BubbleSort(int MaxCount)
    {
    for (int Bubble = 0; Bubble < MaxCount -1; Bubble++)
        {
        for (int pars = 0; pars < MaxCount - Bubble -1; pars++)
            {
            if (data [pars] > data [pars+1])
                {
                Swaps (&data [pars], &data [pars+1]);

                }
            }
        }
     return;
     }
void SelectSort (int MaxCount)
    {

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
    }

void QuickSort (int left, int right)
    {
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





void FillArray ( int MaxCount, int TypeFill)
    {
    for (int i = 0; i<MaxCount; i++)
        {
        assert ( 0 <= i && i<MaxCount);
        if (TypeFill == RandomFill)   data [i] = random(10, 20); //(1, MaxCount);
        if (TypeFill == SortFill)     data [i] = i;
        if (TypeFill == LimitRandom)  data [i] = random (0, 10);
        if (TypeFill == BackSortFill) data [i] = MaxCount - i;
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

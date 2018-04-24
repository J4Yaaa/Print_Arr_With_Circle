#include <stdio.h>

#define ROW 4
#define COL 4

void PrintMatrixInCycle(int arr[ROW][COL],int start,int row,int col)
{
    int endY = col - start - 1;
    int endX = row - start - 1;
    int i = 0;
    //1.从左到右打印
    for(i = start; i <= endY; ++i)
    {
        printf("%d ",arr[start][i]);
    }

    //2.从上到小打印
    //  至少有两行
    if(start < endX)
    {
        for(i = start + 1;i <= endX; ++i)
        {
            printf("%d ",arr[i][endY]);
        }
    }

    //3.从右向左打印
    //  至少有两列并且至少有两行
    if(endY > start && endX > start)
    {
        for(i = endY - 1; i >= start; --i)
        {
            printf("%d ",arr[endX][i]);
        }
    }

    //4.从下到上打印
    //  至少有三行,至少有两列
    if(endX > start + 1 && endY > start)
    {
        for(i = endX - 1; i > start; --i)
        {
            printf("%d ",arr[i][start]);
        }
    }
}

void PrintArrClockwise(int arr[ROW][COL],int row,int col)
{
    if(arr == NULL)
    {
        return;
    }
    if(row <= 0 || col <= 0)
    {
        return;
    }
    int start = 0;
    while(row > start*2 && col > start*2)
    {
        PrintMatrixInCycle(arr,start,row,col);
        ++start;
    }
    printf("\n");
}

void Test()
{
    int arr[ROW][COL] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    PrintArrClockwise(arr,ROW,COL);
}

int main()
{
    Test();
    return 0;
}

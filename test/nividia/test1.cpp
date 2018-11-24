#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void print(int n)
{
    // Complete your code here
    // Numbers must be separated by one space
    //if (n == 24) {
    //    printf("0 1 2 3 4\n");
    //    printf("15 16 17 18 5\n");
    //    printf("14 23 24 19 6\n");
    //    printf("13 22 21 20 7\n");
    //    printf("12 11 10 9 8\n");
    //}
    
    int w;
    int ** arr;
    int dw;
    int start;
    int first;
    w = sqrt(n + 1);
    printf("%d\n",w);

    arr = (int **) malloc(sizeof(int*)*w);
    for(int i = 0; i < w; i++)
    {
        arr[i] = (int *) malloc(sizeof(int)*w);
    }

    dw = w;         // dynamic width;
    start = 0;      // start point;
    first = 0;      // first num in one cycle;
    while( dw > 0 )
    {
        if(dw == 1) { arr[start][start] = first; break; }
        for (int i = 0; i < dw - 1; i ++) 
        {  
            arr[start + i][start]      = first + i;
            arr[start + dw - 1][start + i] = first + (dw-1) + i;
            arr[start+dw-1-i][start+dw-1] = first + 2*(dw-1) + i;
            arr[start][start+dw-1-i] = first + 3*(dw-1) + i;
        }
        start = start + 1;
        first = first + 4*(dw-1);
        dw = dw - 2;
        //printf("-- %d ---\n",dw);
    }


    for(int i = 0; i < w; i++)
    {
        for(int n = 0; n < w; n ++){ printf("%d", arr[n][i]); if(n == w-1) {printf("\n");}else{printf(" ");}}
    }

    free(arr);
}

// ----------------------------
// DO NOT TOUCH THIS CODE BLOCK
#ifndef __NVIDIA_TEST_
// ----------------------------

int main()
{
    // Small test case
    print(24);
    print(48);
    print(35);
    print(399);

    // Large test case
    //print(5000 * 5000 - 1);

    // Write your own tests here

}

// ----------------------------
// DO NOT TOUCH THIS CODE BLOCK
#endif
// ----------------------------

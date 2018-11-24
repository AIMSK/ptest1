#include <stdio.h>

int is_interlace(const char* a, const char* b, const char* c)
{
    // Complete your code here
    return 1;
}

// ----------------------------
// DO NOT TOUCH THIS CODE BLOCK
#ifndef __NVIDIA_TEST_
// ----------------------------

int main()
{
    const char* a = "AAA";
    const char* b = "B";
    const char* c = "ABAA";
    char d[10001], e[10001], f[20001];
    int i;

    // Small test case
    if (is_interlace(a, b, c))
        printf("is_interlace('AAA', 'B', 'ABAA') = Yes\n");
    else
        printf("is_interlace('AAA', 'B', 'ABAA') = No\n");
    
    // Large test case
    for(i = 0; i < 10000; i++)
        d[i] = e[i] = 'A';
    for(i = 0; i < 19999; i++)
        f[i] = 'A';
    f[19999] = '#';
    d[10000] = e[10000] = f[20000] = 0;
    if (is_interlace(d, e, f))
        printf("is_interlace('A...A', 'A...A', 'A...A#') = Yes\n");
    else
        printf("is_interlace('A...A', 'A...A', 'A...A#') = No\n");

    // Write your own tests here

    return 0;
}

// ----------------------------
// DO NOT TOUCH THIS CODE BLOCK
#endif
// ----------------------------

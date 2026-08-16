#include <stdbool.h>


bool func(int a, int b, int c, int d)
{
    //@ assert 1 <= a * b <= 100000000;
    //@ assert 1 <= c * d <= 100000000;
    return a * b > c * d;
}

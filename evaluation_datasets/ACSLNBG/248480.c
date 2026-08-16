#include <stdbool.h>


int func(int a, int b)
{
    int res;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;

    res = a * b;

    //@ assert res == ((a) * (b));
    return res;
}

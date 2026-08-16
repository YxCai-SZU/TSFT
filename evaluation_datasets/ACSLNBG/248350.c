#include <stdbool.h>


bool func(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned k)
{
    bool res;
    //@ assert ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    res = (e - a) <= k;
    //@ assert res == (e - a <= k);
    return res;
}

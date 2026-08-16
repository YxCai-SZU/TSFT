#include <stdbool.h>

/*@
    requires ((a) < 0x80000000 && (b) < 0x80000000 && (c) < 0x80000000 &&
        (d) < 0x80000000 && (e) < 0x80000000 && (k) < 0x80000000 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) &&
        (e) - (a) <= 0x7FFFFFFF);
    ensures \result == (e - a <= k);
*/
bool func(unsigned int a, unsigned int b, unsigned int c,
          unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int diff;

    diff = e - a;
    //@ assert diff <= 0x7FFFFFFF;
    return diff <= k;
}

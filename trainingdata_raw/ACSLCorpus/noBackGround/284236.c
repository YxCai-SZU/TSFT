#include <stddef.h>

/*@
    requires 2 <= a && a <= 100;
    requires 2 <= b && b <= 100;
    ensures \result == a * b - a - b + 1;
    ensures \result > 0;
*/
size_t func(size_t a, size_t b)
{
    // Variable declarations at top of scope
    size_t result;

    //@ assert (2 <= (a) && (a) <= 100 && 2 <= (b) && (b) <= 100);
    //@ assert a * b <= 10000;
    //@ assert a * b - a >= 0;
    //@ assert a * b - a - b >= -99;
    //@ assert a * b - a - b + 1 > 0;

    result = a * b - a - b + 1;
    return result;
}

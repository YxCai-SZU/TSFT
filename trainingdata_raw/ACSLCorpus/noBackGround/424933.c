#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result >= 0;
    ensures \result == b * c || \result == b * d || \result == c * d || 
            \result == a * c || \result == a * d || \result == a * b;
*/
int func(int a, int b, int c, int d)
{
    int max1;
    int max2;
    int result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);

    max1 = a > b ? a : b;
    //@ assert (1 <= (max1) <= 100);

    max2 = c > d ? c : d;
    //@ assert (1 <= (max2) <= 100);

    //@ assert 0 <= max1 * max2 <= 10000;
    result = max1 * max2;

    //@ assert result >= 0;
    //@ assert result == b * c || result == b * d || result == c * d || result == a * c || result == a * d || result == a * b;

    return result;
}

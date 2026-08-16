#include <stdbool.h>

/*@
    requires a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0 && k >= 0;
    requires a <= 123 && b <= 123 && c <= 123 && d <= 123 && e <= 123 && k <= 123;
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (e - a <= k);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    //@ assert e >= 0 && a >= 0;
    //@ assert e - a >= 0;
    return e - a <= k;
}

#include <limits.h>

/*@
    requires (INT_MIN <= (a) <= INT_MAX) && (INT_MIN <= (b) <= INT_MAX) && (INT_MIN <= (c) <= INT_MAX);
    ensures \result == (a < b && b < c);
*/
int func(int a, int b, int c)
{
    // Variable declarations at scope top
    int result;

    //@ assert INT_MIN <= a <= INT_MAX;
    //@ assert INT_MIN <= b <= INT_MAX;
    //@ assert INT_MIN <= c <= INT_MAX;

    if (a < b && b < c) {
        result = 1;
    } else {
        result = 0;
    }

    return result;
}

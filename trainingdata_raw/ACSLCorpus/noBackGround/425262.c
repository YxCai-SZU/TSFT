#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    requires ((m) % 2 == 0);
    ensures \result == n + ((m) / 2);
*/
int func(int n, int m)
{
    int half_m;
    int i;

    half_m = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= m;
        loop invariant half_m * 2 == i;
        loop invariant 1 <= n <= 100;
        loop invariant 1 <= m <= 100;
        loop invariant ((m) % 2 == 0);
        loop assigns half_m, i;
    */
    while (i < m)
    {
        //@ assert i + 2 <= m;
        half_m = half_m + 1;
        i = i + 2;
    }

    //@ assert half_m == ((m) / 2);
    return n + half_m;
}

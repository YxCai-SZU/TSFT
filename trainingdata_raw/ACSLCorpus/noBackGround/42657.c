#include <stdbool.h>

/*@
    requires 1 <= n <= 100000;
    ensures \result == 0 || \result == 1;
*/
int func(int n)
{
    int a = 0;
    int b = 0;
    int temp_n = n;

    /*@
        loop invariant 1 <= n <= 100000;
        loop invariant 0 <= temp_n <= n;
        loop invariant a >= 0;
        loop invariant temp_n == n - 3 * a;
        loop assigns temp_n, a;
        loop variant temp_n;
    */
    while (temp_n >= 3)
    {
        //@ assert temp_n >= 3;
        temp_n -= 3;
        a += 1;
    }

    /*@
        loop invariant 1 <= n <= 100000;
        loop invariant 0 <= temp_n <= n;
        loop invariant b >= 0;
        loop invariant temp_n == n - 3 * a - 5 * b;
        loop assigns temp_n, b;
        loop variant temp_n;
    */
    while (temp_n >= 5)
    {
        //@ assert temp_n >= 5;
        temp_n -= 5;
        b += 1;
    }

    //@ assert temp_n == n - 3 * a - 5 * b;
    if ((a >= 1 && b >= 1) || (a >= 2 && b >= 2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

#include <stdbool.h>

/*@
    requires 1 <= n <= 10000;
    ensures \result == (n % 2 == 0 || n % 5 == 0);
    assigns \nothing;
*/
bool func(int n)
{
    int a;
    int i;

    a = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant a == 2 * i;
        loop invariant 1 <= n <= 10000;
        loop assigns a, i;
        loop variant n - i;
    */
    while (i < n)
    {
        a = a + 2;
        i = i + 1;
    }

    //@ assert a == 2 * n;
    return (n % 2 == 0) || (n % 5 == 0);
}

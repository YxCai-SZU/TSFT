#include <stdint.h>

/*@
    requires (1 <= (n) <= 100000000000);
    ensures \result == (((n) / 3) + ((n) % 3));
    ensures \result == (n / 3) + (n % 3);
*/
int64_t func(int64_t n)
{
    int64_t div;
    int64_t rem;

    div = 0;
    rem = n;

    /*@
        loop invariant 1 <= n <= 100000000000;
        loop invariant 0 <= div;
        loop invariant div <= n / 3;
        loop invariant rem == n - 3 * div;
        loop assigns div, rem;
    */
    while (rem >= 3)
    {
        rem = rem - 3;
        div = div + 1;
    }

    return div + rem;
}

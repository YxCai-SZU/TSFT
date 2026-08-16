#include <stdint.h>

/*@
    requires (1 <= (k) <= (n) <= 50);
    ensures \result == ((n) - (k) + 1);
*/
int64_t func(int64_t n, int64_t k)
{
    int64_t result;
    int64_t i;

    result = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= k;
        loop invariant result == i;
        loop invariant (1 <= (k) <= (n) <= 50);
        loop invariant result <= k;
        loop assigns i, result;
    */
    while (i < k)
    {
        i = i + 1;
        result = result + 1;
    }

    //@ assert result == k;

    //@ assert n - k >= 0;
    //@ assert (n - k) + 1 <= 51;

    return n - k + 1;
}

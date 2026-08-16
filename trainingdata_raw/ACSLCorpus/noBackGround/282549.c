#include <stdint.h>

/*@
    requires (2 <= (n) && (n) <= 1000000000000);
    ensures \result <= n - 1;
    ensures \result >= 0;
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t i;
    uint64_t res;

    //@ assert n - 1 >= 0;
    i = 2;

    /*@
        loop invariant 2 <= i <= n;
        loop invariant n - 1 >= 0;
        loop assigns i;
        loop variant n - i;
    */
    while (i < n)
    {
        if (n % i == 0)
        {
            //@ assert i > 1;
            //@ assert n / i >= 1;
            res = n / i - 1;
            //@ assert res <= n - 1;
            //@ assert res >= 0;
            return res;
        }
        i = i + 1;
    }

    //@ assert n - 1 >= 0;
    res = n - 1;
    //@ assert res <= n - 1;
    //@ assert res >= 0;
    return res;
}

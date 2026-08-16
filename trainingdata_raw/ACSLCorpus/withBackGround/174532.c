#include <stdint.h>

/*@
    predicate is_even(integer n) = n % 2 == 0;
    predicate is_odd(integer n) = n % 2 != 0;
    logic integer odd_formula(integer n) = (n / 2 + 1) * 2 / n;
*/

/*@
    requires 1 <= n <= 100;
    ensures is_even(n) ==> \result == 1;
    ensures is_odd(n) ==> \result == odd_formula(n);
*/
int32_t func(uint32_t n)
{
    int32_t result;

    if (n % 2 == 0)
    {
        //@ assert is_even(n);
        result = 1;
    }
    else
    {
        //@ assert is_odd(n);
        //@ assert n / 2 + 1 <= n;
        //@ assert (n / 2 + 1) * 2 <= n * 2;
        result = (n / 2 + 1) * 2 / n;
    }

    return result;
}

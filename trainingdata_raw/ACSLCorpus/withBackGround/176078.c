#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100000;

    logic integer division(integer x, integer n) = x / n;
    logic integer modulo(integer x, integer n) = x % n;

    lemma division_modulo_property:
        \forall integer x, n; n > 0 ==> x == division(x, n) * n + modulo(x, n);

    predicate result_condition(integer x) = 
        x >= 2000 || modulo(x, 200) == 0;
*/

/*@
    requires is_valid_range(x);
    ensures \result == (x >= 2000 || x % 200 == 0);
    assigns \nothing;
*/
bool func(unsigned int x)
{
    unsigned int n;
    unsigned int quotient;
    unsigned int remainder;
    unsigned int remaining;
    unsigned int divisor;
    unsigned int temp_remaining;

    n = 200;
    quotient = x / n;
    remainder = x % n;

    if (quotient >= 10 || remainder == 0)
    {
        //@ assert x >= 2000 || x % 200 == 0;
        return true;
    }

    remaining = x - (quotient * n);
    divisor = 0;
    temp_remaining = remaining;

    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant n == 200;
        loop invariant quotient == division(x, n);
        loop invariant remainder == modulo(x, n);
        loop invariant 0 <= divisor <= division(remaining, n);
        loop invariant temp_remaining == remaining - divisor * n;
        loop invariant 0 <= temp_remaining < 200 + remaining;
        loop assigns divisor, temp_remaining;
        loop variant temp_remaining;
    */
    while (temp_remaining >= 200)
    {
        temp_remaining -= 200;
        divisor += 1;
    }

    if (divisor + quotient >= 10)
    {
        //@ assert x >= 2000 || x % 200 == 0;
        return true;
    }

    //@ assert !(x >= 2000 || x % 200 == 0);
    return false;
}

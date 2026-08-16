#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer a) =
        1 <= n && n <= 10000 &&
        0 <= a && a <= 1000;

    logic integer manual_mod(integer n) =
        n % 500;

    lemma mod_property:
        \forall integer n, integer a;
        valid_params(n, a) ==>
        (manual_mod(n) <= a) == (n % 500 <= a);
*/

/*@
    requires valid_params(n, a);
    ensures \result == (n % 500 <= a);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int a)
{
    unsigned int quotient = 0;
    unsigned int remainder = n;

    /*@
        loop invariant 0 <= quotient <= n / 500;
        loop invariant remainder == n - quotient * 500;
        loop invariant valid_params(n, a);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 500)
    {
        quotient += 1;
        remainder -= 500;
    }

    //@ assert remainder == n % 500;
    
    return remainder <= a;
}

#include <stdbool.h>

/*@
    predicate is_valid_range(integer n) =
        1 <= n && n <= 10000;

    logic integer manual_division(integer n) =
        (n / 100) * 100 + (n % 100);

    lemma division_property:
        \forall integer n; is_valid_range(n) ==> 
            n == (n / 100) * 100 + (n % 100);
*/

/*@
    requires is_valid_range(n);
    ensures \result == manual_division(n);
    assigns \nothing;
*/
int func(int n)
{
    int quotient = 0;
    int remainder = n;

    /*@
        loop invariant 0 <= remainder <= 10000;
        loop invariant quotient <= n / 100;
        loop invariant n == quotient * 100 + remainder;
        loop invariant is_valid_range(n);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 100)
    {
        quotient += 1;
        remainder -= 100;
    }

    //@ assert remainder < 100;
    //@ assert quotient * 100 + remainder <= 10000;
    //@ assert quotient * 100 + remainder >= 0;

    return quotient * 100 + remainder;
}

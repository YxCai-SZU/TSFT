#include <stdbool.h>

/*@
    predicate is_valid_range(integer n) =
        10 <= n && n <= 99;

    logic integer abs_val(integer n) =
        n < 0 ? -n : n;

    logic integer manual_div(integer n_abs, integer remainder) =
        n_abs - remainder;

    logic integer manual_mod(integer n_abs, integer quotient) =
        n_abs - quotient * 10;
*/

/*@
    requires is_valid_range(n);
    ensures \result == (n % 10 == 9 || n / 10 == 9);
*/
bool func(int n)
{
    int n_abs;
    int quotient;
    int remainder;

    // Declare all variables at top
    n_abs = n < 0 ? -n : n;
    quotient = 0;
    remainder = n_abs;

    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= n_abs / 10;
        loop invariant remainder == n_abs - quotient * 10;
        loop invariant is_valid_range(n);
        loop assigns quotient, remainder;
    */
    while (remainder >= 10)
    {
        quotient += 1;
        remainder -= 10;
    }

    //@ assert quotient == n / 10;
    //@ assert remainder == n % 10;
    
    return quotient == 9 || remainder == 9;
}

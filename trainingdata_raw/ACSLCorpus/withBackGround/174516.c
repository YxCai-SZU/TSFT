#include <limits.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer manual_div(integer n, integer d) = n / d;

    logic integer func_spec(integer n) = 
        n * 800 - (n / 15) * 200;

    lemma no_overflow:
        \forall integer n; valid_n(n) ==> n * 800 <= 100 * 800;
*/

/*@
    requires valid_n(n);
    ensures \result == func_spec(n);
    assigns \nothing;
*/
int func(int n)
{
    int x;
    int quotient;
    int remainder;
    int y;
    int ans;

    //@ assert valid_n(n);
    //@ assert n * 800 <= 100 * 800;

    x = 800 * n;

    quotient = 0;
    remainder = n;

    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 0 <= quotient && quotient <= n / 15;
        loop invariant 0 <= remainder && remainder < 15 + n;
        loop invariant remainder == n - quotient * 15;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 15)
    {
        //@ assert remainder >= 15;
        quotient = quotient + 1;
        remainder = remainder - 15;
        //@ assert remainder == n - quotient * 15;
    }

    y = 200 * quotient;
    ans = x - y;

    //@ assert ans == func_spec(n);
    return ans;
}

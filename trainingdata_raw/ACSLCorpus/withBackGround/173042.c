#include <stddef.h>

/*@
    predicate division_invariant_500(integer q, integer r, integer x) =
        q >= 0 && r >= 0 && r + q * 500 == x && q <= x / 500;

    predicate division_invariant_5(integer q, integer r, integer x) =
        q >= 0 && r >= 0 && r + q * 5 == x && q <= x / 5;

    logic integer compute_result(integer x) =
        (x / 500) * 1000 + ((x % 500) / 5) * 5;
*/

/*@
    requires 1 <= x && x <= 100000;
    ensures \result == compute_result(x);
    assigns \nothing;
*/
size_t func(size_t x)
{
    size_t x_local = x;
    size_t ans = 0;
    size_t quotient_500 = 0;
    size_t remainder_500 = x_local;

    /*@
        loop invariant division_invariant_500(quotient_500, remainder_500, x_local);
        loop assigns quotient_500, remainder_500;
        loop variant remainder_500;
    */
    while (remainder_500 >= 500)
    {
        quotient_500 += 1;
        remainder_500 -= 500;
        //@ assert division_invariant_500(quotient_500, remainder_500, x_local);
    }
    ans += quotient_500 * 1000;
    x_local = remainder_500;

    size_t quotient_5 = 0;
    size_t remainder_5 = x_local;

    /*@
        loop invariant division_invariant_5(quotient_5, remainder_5, x_local);
        loop assigns quotient_5, remainder_5;
        loop variant remainder_5;
    */
    while (remainder_5 >= 5)
    {
        quotient_5 += 1;
        remainder_5 -= 5;
        //@ assert division_invariant_5(quotient_5, remainder_5, x_local);
    }
    ans += quotient_5 * 5;
    x_local = remainder_5;

    //@ assert ans == compute_result(x);
    return ans;
}

/*@
    assigns \nothing;
*/
int main(void)
{
    return 0;
}

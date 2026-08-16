#include <limits.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer multiply_800(integer n) = n * 800;
    logic integer divide_15(integer n) = n / 15;
    logic integer multiply_200(integer q) = q * 200;
    logic integer final_result(integer n) = multiply_800(n) - multiply_200(divide_15(n));

    lemma no_overflow_mult_800: \forall integer n; valid_n(n) ==> multiply_800(n) <= 80000;
    lemma quotient_bound: \forall integer n; valid_n(n) ==> divide_15(n) <= 6;
    lemma no_overflow_mult_200: \forall integer n; valid_n(n) ==> multiply_200(divide_15(n)) <= 1200;
*/

/*@
    requires valid_n(n);
    ensures \result == final_result(n);
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at scope top
    int x;
    int quotient = 0;
    int temp_n = n;
    int y;
    int ans;

    //@ assert valid_n(n);
    //@ assert multiply_800(n) <= 80000;
    x = n * 800;

    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= quotient;
        loop invariant 0 <= temp_n;
        loop invariant n == temp_n + quotient * 15;
        loop invariant temp_n < 15 ==> quotient == divide_15(n);
        loop assigns quotient, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        temp_n -= 15;
        quotient += 1;
    }

    //@ assert quotient <= 6;
    //@ assert multiply_200(quotient) <= 1200;
    y = quotient * 200;

    //@ assert x - y == final_result(n);
    ans = x - y;
    return ans;
}

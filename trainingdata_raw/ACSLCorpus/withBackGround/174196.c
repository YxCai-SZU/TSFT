#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;

    logic integer multiply_800(integer n) = n * 800;
    logic integer divide_15(integer n) = n / 15;
    logic integer multiply_200(integer q) = 200 * q;
    logic integer final_result(integer n) = 
        multiply_800(n) - multiply_200(divide_15(n));

    lemma overflow_bound: \forall integer n; is_valid_n(n) ==> multiply_800(n) <= 80000;
    lemma quotient_bound: \forall integer n; is_valid_n(n) ==> divide_15(n) <= 6;
    lemma product_bound: \forall integer n; is_valid_n(n) ==> multiply_200(divide_15(n)) <= 1200;
*/

/*@
    requires 1 <= n && n <= 100;
    ensures \result == final_result(n);
*/
int64_t func(uint64_t n)
{
    uint64_t x;
    uint64_t quotient = 0;
    uint64_t remainder = n;
    uint64_t divisor = 15;
    uint64_t y;
    uint64_t ans;

    //@ assert is_valid_n(n);
    //@ assert multiply_800(n) <= 80000;
    x = n * 800;

    /*@
        loop invariant 0 <= quotient && quotient <= n / divisor;
        loop invariant 0 <= remainder && remainder < n + 1;
        loop invariant remainder + divisor * quotient == n;
        loop invariant is_valid_n(n);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }

    //@ assert quotient <= n / 15;
    //@ assert multiply_200(quotient) <= multiply_200(divide_15(n));
    y = 200 * quotient;

    //@ assert x - y == final_result(n);
    ans = x - y;

    return (int64_t)ans;
}

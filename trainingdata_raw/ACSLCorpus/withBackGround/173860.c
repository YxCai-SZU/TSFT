#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 2 <= n && n <= 100;

    logic integer half(integer n) = n / 2;
    logic integer half_plus_one(integer n) = (n + 1) / 2;
    logic integer target_result(integer n) = half(n) * half_plus_one(n);

    lemma multiplication_bounds:
        \forall integer n; is_valid_n(n) ==> half(n) * half_plus_one(n) <= 50 * 50;
*/

/*@
    requires is_valid_n(n);
    ensures \result == target_result(n);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t n2;
    uint64_t temp_n;
    uint64_t n3;
    uint64_t ans;

    n2 = 0;
    temp_n = n;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant n2 <= half(n);
        loop invariant n == temp_n + 2 * n2;
        loop invariant is_valid_n(n);
        loop assigns temp_n, n2;
        loop variant temp_n;
    */
    while (temp_n > 1)
    {
        temp_n -= 2;
        n2 += 1;
    }

    //@ assert n2 == half(n);

    n3 = 0;
    temp_n = n + 1;

    /*@
        loop invariant 0 <= temp_n <= n + 1;
        loop invariant n3 <= half_plus_one(n);
        loop invariant temp_n == n + 1 - 2 * n3;
        loop invariant is_valid_n(n);
        loop assigns temp_n, n3;
        loop variant temp_n;
    */
    while (temp_n > 1)
    {
        temp_n -= 2;
        n3 += 1;
    }

    //@ assert n3 == half_plus_one(n);
    //@ assert n2 * n3 <= 50 * 50;

    ans = n2 * n3;
    return ans;
}

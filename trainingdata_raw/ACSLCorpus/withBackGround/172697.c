#include <stddef.h>

/*@
    predicate is_valid_n(integer n) = 2 <= n && n <= 100000;

    logic integer half_calc(integer n, integer count) = (n - count) / 2;

    lemma loop_invariant_maintained:
        \forall integer n, count, half_n;
        is_valid_n(n) && 0 <= count && count <= n &&
        half_n == half_calc(n, count) && count + 2 * half_n == n &&
        count >= 2 ==>
        half_calc(n, count - 2) == half_n + 1 &&
        (count - 2) + 2 * (half_n + 1) == n;

    lemma final_result_correct:
        \forall integer n, count, half_n;
        is_valid_n(n) && 0 <= count && count <= n &&
        half_n == half_calc(n, count) && count + 2 * half_n == n &&
        count < 2 ==>
        half_n + count == n / 2 + n % 2;
*/

/*@
    requires is_valid_n(n);
    ensures \result == n / 2 + n % 2;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t half_n = 0;
    size_t count = n;

    /*@
        loop invariant 0 <= count <= n;
        loop invariant half_n == half_calc(n, count);
        loop invariant count + 2 * half_n == n;
        loop invariant is_valid_n(n);
        loop assigns count, half_n;
        loop variant count;
    */
    while (count >= 2)
    {
        //@ assert count >= 2;
        count -= 2;
        half_n += 1;
        //@ assert half_n == half_calc(n, count);
        //@ assert count + 2 * half_n == n;
    }

    size_t ans = half_n + count;

    //@ assert half_n == n / 2;
    //@ assert ans == half_n + n % 2;
    //@ assert ans == n / 2 + n % 2;

    return ans;
}

int main()
{
    return 0;
}

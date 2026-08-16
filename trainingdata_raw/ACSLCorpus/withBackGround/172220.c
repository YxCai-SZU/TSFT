/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer division_by_subtraction(integer n, integer count) =
        n - count * 15;

    logic integer final_result(integer n) =
        n * 800 - n / 15 * 200;

    lemma division_property:
        \forall integer n, count;
        valid_n(n) && count == n / 15 ==>
        division_by_subtraction(n, count) == n % 15;
*/

#include <stdint.h>

/*@
    requires valid_n(n);
    ensures \result == final_result(n);
    assigns \nothing;
*/
int32_t func(int32_t n)
{
    int32_t ans;
    int32_t temp_n;
    int32_t count;

    ans = n * 800;
    temp_n = n;
    count = 0;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant count <= n / 15;
        loop invariant temp_n == division_by_subtraction(n, count);
        loop invariant valid_n(n);
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        temp_n -= 15;
        count += 1;
    }

    ans -= count * 200;

    //@ assert count == n / 15;
    //@ assert temp_n == n - count * 15;
    //@ assert 0 <= temp_n && temp_n < 15;
    //@ assert ans == n * 800 - count * 200;
    //@ assert ans == final_result(n);

    return ans;
}

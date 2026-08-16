#include <stdint.h>

/*@
    predicate is_valid_n(integer n) =
        1 <= n <= 1000000000;

    logic integer half_calc(integer n, integer temp) =
        (n - temp) / 2;

    logic integer remainder_calc(integer temp) =
        temp == 1 ? 1 : 0;

    logic integer final_result(integer n, integer temp) =
        half_calc(n, temp) + remainder_calc(temp);
*/

/*@
    requires is_valid_n(n);
    ensures \result == n / 2 + n % 2;
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t half_n;
    uint64_t temp_n;
    uint64_t count;
    uint64_t remainder;
    uint64_t ans;

    half_n = 0;
    temp_n = n;
    count = 0;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant half_n == (n - temp_n) / 2;
        loop invariant count == (n - temp_n) / 2;
        loop invariant temp_n == n - 2 * count;
        loop invariant is_valid_n(n);
        loop assigns temp_n, half_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        //@ assert temp_n >= 2;
        temp_n -= 2;
        half_n += 1;
        count += 1;
    }

    //@ assert temp_n < 2;
    remainder = (temp_n == 1) ? 1 : 0;
    //@ assert remainder == remainder_calc(temp_n);

    ans = half_n + remainder;
    //@ assert ans == final_result(n, temp_n);
    //@ assert ans == n / 2 + n % 2;

    return ans;
}

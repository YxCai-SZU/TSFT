#include <stdint.h>

/*@
    requires (1 <= (a) <= 123 &&
        1 <= (b) <= 123 &&
        1 <= (c) <= 123 &&
        1 <= (d) <= 123 &&
        1 <= (e) <= 123);
    ensures \result == (a + b + c + d + e + 5) / 5;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d, uint64_t e)
{
    // Variable declarations at scope top
    uint64_t min_val;
    uint64_t sum;
    uint64_t ans;
    uint64_t temp_sum;

    // Input validation assertions
    //@ assert 1 <= a <= 123;
    //@ assert 1 <= b <= 123;
    //@ assert 1 <= c <= 123;
    //@ assert 1 <= d <= 123;
    //@ assert 1 <= e <= 123;

    // Sum bound verification
    //@ assert a + b + c + d + e <= 615;

    // Sum+5 bound verification
    //@ assert a + b + c + d + e + 5 <= 620;

    // Find minimum value
    min_val = (a < b) ? a : b;
    min_val = (min_val < c) ? min_val : c;
    min_val = (min_val < d) ? min_val : d;
    min_val = (min_val < e) ? min_val : e;

    sum = a + b + c + d + e;
    ans = 0;
    temp_sum = sum + 5;

    /*@
        loop invariant 1 <= a <= 123;
        loop invariant 1 <= b <= 123;
        loop invariant 1 <= c <= 123;
        loop invariant 1 <= d <= 123;
        loop invariant 1 <= e <= 123;
        loop invariant sum == a + b + c + d + e;
        loop invariant temp_sum >= 0;
        loop invariant ans >= 0;
        loop invariant temp_sum == sum + 5 - 5 * ans;
        loop assigns temp_sum, ans;
        loop variant temp_sum;
    */
    while (temp_sum >= 5)
    {
        temp_sum -= 5;
        ans += 1;
    }

    return ans;
}

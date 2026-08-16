#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;

    logic integer total_positive(integer n, integer i, integer x) = i * x;
    logic integer total_negative(integer n, integer i, integer x, integer y) = n * x - i * y;

    lemma final_result:
        \forall integer n, integer x, integer y;
        is_valid_n(n) && x == 800 && y == 200 ==>
        total_negative(n, n/15, x, y) == n * x - (n/15) * y;
*/

/*@
    requires is_valid_n(n);
    ensures \result == n * 800 - (n / 15) * 200;
*/
int32_t func(uint32_t n)
{
    int32_t x;
    int32_t y;
    int32_t ans;
    uint32_t i;

    x = 800;
    y = 200;
    ans = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant ans == total_positive(n, i, x);
        loop invariant x == 800;
        loop invariant y == 200;
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert ans + x == total_positive(n, i+1, x);
        ans += x;
        i += 1;
    }

    i = 0;

    /*@
        loop invariant 0 <= i <= n/15;
        loop invariant ans == total_negative(n, i, x, y);
        loop invariant x == 800;
        loop invariant y == 200;
        loop assigns ans, i;
        loop variant (n/15) - i;
    */
    while (i < n / 15)
    {
        //@ assert ans - y == total_negative(n, i+1, x, y);
        ans -= y;
        i += 1;
    }

    //@ assert ans == n * 800 - (n / 15) * 200;
    return ans;
}

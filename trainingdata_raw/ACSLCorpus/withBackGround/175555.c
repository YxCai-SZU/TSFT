#include <limits.h>

/*@
    predicate valid_range(integer n) =
        1 <= n <= 10000;

    logic integer division_count(integer n, integer temp_n) =
        (n - temp_n) / 1000;

    logic integer final_result(integer n, integer count) =
        (count + 1) * 1000 - n;
*/

/*@
    requires valid_range(n);
    ensures \result == (n / 1000 + 1) * 1000 - n;
    assigns \nothing;
*/
int func(int n)
{
    int ans;
    int temp_n;
    int count;

    //@ assert valid_range(n);
    ans = 0;
    temp_n = n;
    count = 0;

    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= temp_n <= n;
        loop invariant count <= n / 1000;
        loop invariant temp_n == n - count * 1000;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 1000)
    {
        //@ assert temp_n >= 1000;
        temp_n -= 1000;
        count += 1;
        //@ assert temp_n == n - count * 1000;
    }

    //@ assert temp_n == n - count * 1000;
    //@ assert temp_n < 1000;
    ans = (count + 1) * 1000 - n;
    //@ assert ans == final_result(n, count);
    return ans;
}

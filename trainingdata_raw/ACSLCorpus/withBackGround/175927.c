#include <stdbool.h>

/*@
    predicate is_valid_range(integer n) = 1 <= n <= 100;

    logic integer total_deduction(integer n, integer cnt) = n * 800 - cnt * 200;

    lemma count_property:
        \forall integer n, cnt;
        is_valid_range(n) && 0 <= cnt <= n / 15 ==>
        total_deduction(n, cnt) == n * 800 - cnt * 200;
*/

/*@
    requires is_valid_range(n);
    ensures \result == n * 800 - (n / 15) * 200;
    assigns \nothing;
*/
int func(int n)
{
    int res;
    int temp_n;
    int count;

    res = n * 800;
    temp_n = n;
    count = 0;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= n / 15;
        loop invariant res == n * 800;
        loop invariant temp_n == n - count * 15;
        loop assigns count, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        count = count + 1;
        temp_n = temp_n - 15;
    }

    //@ assert count == n / 15;
    res = res - count * 200;
    return res;
}

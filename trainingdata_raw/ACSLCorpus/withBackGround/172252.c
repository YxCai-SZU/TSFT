#include <stdint.h>

/*@
    predicate cnt_in_range(integer cnt, integer n) =
        0 <= cnt <= n / 2;

    predicate temp_relation(integer temp, integer n, integer cnt) =
        temp == n - 2 * cnt;

    predicate n_in_range(integer n) =
        1 <= n <= 1000000000;

    logic integer result_value(integer n) =
        n / 2 + n % 2;
*/

/*@
    requires 1 <= n <= 1000000000;
    ensures \result == result_value(n);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t cnt;
    uint64_t temp;

    cnt = 0;
    temp = n;

    /*@
        loop invariant cnt_in_range(cnt, n);
        loop invariant temp_relation(temp, n, cnt);
        loop assigns cnt, temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        cnt += 1;
        //@ assert cnt_in_range(cnt, n);
    }

    if (temp == 1)
    {
        //@ assert temp == 1;
        cnt += 1;
    }

    //@ assert cnt == result_value(n);
    return cnt;
}

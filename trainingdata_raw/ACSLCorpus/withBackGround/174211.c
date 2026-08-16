#include <stddef.h>

/*@
    predicate is_in_range(integer n) =
        1 <= n <= 10000;

    logic integer compute_result(integer n) =
        (n - 1) / 100 * 100 + 100;

    lemma result_correctness:
        \forall integer n;
            is_in_range(n) ==>
            compute_result(n) == (n - 1) / 100 * 100 + 100;
*/

/*@
    requires is_in_range(n);
    ensures \result == compute_result(n);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t ans;
    size_t temp;

    if (n % 100 == 0)
    {
        ans = n;
        //@ assert ans == n;
    }
    else
    {
        temp = n / 100;
        temp += 1;
        ans = temp * 100;
        //@ assert ans == (n - 1) / 100 * 100 + 100;
    }

    //@ assert ans == compute_result(n);
    return ans;
}

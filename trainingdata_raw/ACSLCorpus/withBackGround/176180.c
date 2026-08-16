#include <stdbool.h>

/*@
    predicate is_valid_range(integer n) = 1 <= n <= 100;

    logic integer division_by_2(integer n) = (n + 1) / 2;

    lemma division_property:
        \forall integer n; is_valid_range(n) ==> division_by_2(n) == (n + 1) / 2;
*/

/*@
    requires is_valid_range(n);
    ensures \result == division_by_2(n);
    assigns \nothing;
*/
int func(int n)
{
    int result = 0;
    int temp_n = n;

    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= temp_n <= n;
        loop invariant result == (n - temp_n) / 2;
        loop invariant n == temp_n + 2 * result;
        loop assigns temp_n, result;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        temp_n -= 2;
        result += 1;
    }

    if (temp_n == 1)
    {
        result += 1;
    }

    //@ assert 0 <= temp_n < 2;
    //@ assert result == division_by_2(n);

    return result;
}

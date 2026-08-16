#include <stdbool.h>

/*@
    predicate is_valid_range(integer n) = 1 <= n <= 1000;
    predicate loop_invariant(integer n, integer temp_n, integer result) =
        is_valid_range(n) &&
        0 <= result &&
        0 <= temp_n &&
        n == temp_n + result * 3;
    logic integer division_result(integer n) = n / 3;
*/

/*@
    requires is_valid_range(n);
    ensures \result == division_result(n);
    assigns \nothing;
*/
int func(int n)
{
    int result = 0;
    int temp_n = n;
    int three = 3;

    /*@
        loop invariant loop_invariant(n, temp_n, result);
        loop assigns temp_n, result;
        loop variant temp_n;
    */
    while (temp_n >= three)
    {
        //@ assert n == temp_n + result * 3;
        temp_n -= three;
        result += 1;
        //@ assert n == temp_n + result * 3;
    }

    //@ assert n == temp_n + result * 3;
    //@ assert temp_n < 3;
    //@ assert result == division_result(n);
    return result;
}

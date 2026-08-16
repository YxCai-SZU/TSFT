#include <stdbool.h>

/*@
    predicate is_valid_range(integer n) = 1 <= n <= 10000;

    logic integer compute_mod(integer n) = n % 1000;

    logic integer compute_result(integer n_mod) = 
        n_mod == 0 ? 0 : 1000 - n_mod;

    lemma result_properties:
        \forall integer n, result;
        is_valid_range(n) && result == compute_result(n % 1000) ==>
        result >= 0 && result < 1000 &&
        (result == 0 ==> n % 1000 == 0) &&
        (result > 0 ==> n % 1000 + result == 1000);
*/

/*@
    requires is_valid_range(n);
    ensures \result >= 0 && \result < 1000;
    ensures \result == 0 ==> n % 1000 == 0;
    ensures \result > 0 ==> n % 1000 + \result == 1000;
*/
int func(int n)
{
    int n_mod;
    int result;

    n_mod = n;

    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant -999 < n_mod <= n;
        loop invariant n_mod >= 0;
        loop invariant n_mod == n || n_mod % 1000 == n % 1000;
        loop assigns n_mod;
        loop variant n_mod;
    */
    while (n_mod >= 1000)
    {
        n_mod -= 1000;
    }

    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant -999 < n_mod < 1000;
        loop invariant n_mod == n - 1000 * (n / 1000) || 
                      n_mod == n - 1000 * (n / 1000) + 1000;
        loop invariant n_mod % 1000 == n % 1000;
        loop assigns n_mod;
        loop variant 1000 + n_mod;
    */
    while (n_mod < 0)
    {
        n_mod += 1000;
    }

    //@ assert n_mod >= 0 && n_mod < 1000;
    //@ assert n_mod % 1000 == n % 1000;

    if (n_mod == 0)
    {
        result = 0;
    }
    else
    {
        result = 1000 - n_mod;
    }

    //@ assert result >= 0 && result < 1000;
    //@ assert result == 0 ==> n % 1000 == 0;
    //@ assert result > 0 ==> n % 1000 + result == 1000;

    return result;
}

#include <stdbool.h>

/*@
    predicate is_even(integer n) = n % 2 == 0;
    predicate is_odd(integer n) = n % 2 == 1;
    predicate condition_true(integer n, integer k) =
        (is_even(n) && n / 2 >= k) || (is_odd(n) && (n / 2 + 1) >= k);
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == true <==> condition_true(n, k);
*/
bool func(int n, int k)
{
    int n_mod_2;
    int n_div_2;
    int temp;
    bool result;

    n_mod_2 = n % 2;
    n_div_2 = n / 2;

    if (n_mod_2 == 0 && n_div_2 >= k)
    {
        //@ assert condition_true(n, k);
        return true;
    }

    temp = n_div_2 + 1;
    if (n_mod_2 == 1 && temp >= k)
    {
        //@ assert condition_true(n, k);
        return true;
    }

    //@ assert !condition_true(n, k);
    return false;
}

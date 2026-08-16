#include <stdbool.h>

/*@
    predicate is_valid_range(integer n) = 10 <= n && n <= 99;

    logic integer abs_value(integer n) = (n < 0) ? -n : n;

    logic integer division_result(integer n_abs) = n_abs / 10;

    logic integer modulus_result(integer n_abs) = n_abs % 10;

    lemma division_property:
        \forall integer n_abs, temp, div;
            is_valid_range(n_abs) && 0 <= temp <= n_abs && temp == n_abs - 10 * div && div >= 0 ==>
            (temp >= 10 ==> div == division_result(n_abs - temp));

    lemma modulus_property:
        \forall integer n_abs, mod_res;
            is_valid_range(n_abs) && 0 <= mod_res <= n_abs && 
            mod_res == n_abs - 10 * ((n_abs - mod_res) / 10) &&
            0 <= (n_abs - mod_res) / 10 <= 9 ==>
            (mod_res >= 10 ==> (n_abs - mod_res) / 10 == division_result(n_abs - mod_res));
*/

/*@
    requires 10 <= n <= 99;
    ensures \result == (n % 10 == 9 || (n / 10) % 10 == 9);
*/
bool func(int n)
{
    int n_abs;
    int div;
    int temp;
    int mod_res;

    n_abs = n;
    //@ assert is_valid_range(n);
    if (n < 0)
    {
        n_abs = -n;
    }
    //@ assert is_valid_range(n_abs);

    div = 0;
    temp = n_abs;
    /*@
        loop invariant 10 <= n_abs <= 99;
        loop invariant 0 <= temp <= n_abs;
        loop invariant temp == n_abs - 10 * div;
        loop invariant div >= 0;
        loop assigns temp, div;
        loop variant temp;
    */
    while (temp >= 10)
    {
        //@ assert temp >= 10;
        temp -= 10;
        div += 1;
        //@ assert temp == n_abs - 10 * div;
    }

    mod_res = n_abs;
    /*@
        loop invariant 10 <= n_abs <= 99;
        loop invariant 0 <= mod_res <= n_abs;
        loop invariant mod_res == n_abs - 10 * ((n_abs - mod_res) / 10);
        loop invariant 0 <= (n_abs - mod_res) / 10 <= 9;
        loop assigns mod_res;
        loop variant mod_res;
    */
    while (mod_res >= 10)
    {
        //@ assert mod_res >= 10;
        mod_res -= 10;
        //@ assert mod_res == n_abs - 10 * ((n_abs - mod_res) / 10);
    }

    //@ assert div == n_abs / 10;
    //@ assert mod_res == n_abs % 10;
    return div == 9 || mod_res == 9;
}

#include <stdbool.h>

/*@
    predicate is_two_digit(integer n) = 10 <= n && n <= 99;

    logic integer abs_val(integer n) = n >= 0 ? n : -n;

    lemma abs_nonneg: \forall integer n; abs_val(n) >= 0;
    lemma abs_preserve: \forall integer n; n >= 0 ==> abs_val(n) == n;
*/

/*@
    requires is_two_digit(n);
    ensures \result == (n / 10 == 9 || n % 10 == 9);
*/
bool func(int n)
{
    int n_abs;
    int div;
    int temp;
    int mod_res;
    bool result;

    //@ assert is_two_digit(n);
    n_abs = n;
    if (n < 0) {
        n_abs = -n;
    }
    //@ assert n_abs == abs_val(n);
    //@ assert n_abs >= 0;

    div = 0;
    temp = n_abs;
    /*@
        loop invariant 0 <= div;
        loop invariant temp >= 0;
        loop invariant temp == n_abs - 10 * div;
        loop invariant div <= n_abs / 10;
        loop assigns temp, div;
    */
    while (temp >= 10) {
        //@ assert temp >= 10;
        temp -= 10;
        div += 1;
        //@ assert temp == n_abs - 10 * div;
    }
    //@ assert div == n_abs / 10;

    mod_res = n_abs;
    /*@
        loop invariant 0 <= mod_res;
        loop invariant mod_res <= n_abs;
        loop invariant mod_res == n_abs - 10 * (n_abs / 10 - mod_res / 10);
        loop assigns mod_res;
    */
    while (mod_res >= 10) {
        //@ assert mod_res >= 10;
        mod_res -= 10;
        //@ assert mod_res == n_abs - 10 * (n_abs / 10 - mod_res / 10);
    }
    //@ assert mod_res == n_abs % 10;

    result = (div == 9 || mod_res == 9);
    //@ assert result == (n / 10 == 9 || n % 10 == 9);
    return result;
}

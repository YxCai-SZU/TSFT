#include <stdbool.h>

/*@
    predicate is_valid_range(integer n) = 10 <= n && n <= 99;

    logic integer abs_val(integer n) = n < 0 ? -n : n;

    logic integer division_part(integer n_abs, integer temp) = (n_abs - temp) / 10;

    lemma division_property: \forall integer n_abs, temp;
        0 <= temp <= n_abs ==> division_part(n_abs, temp) >= 0;
*/

/*@
    requires is_valid_range(n);
    ensures \result == (n % 10 == 9 || (n / 10) % 10 == 9);
*/
bool func(int n) {
    int n_abs;
    int div;
    int temp;
    int mod_res;

    n_abs = n;
    //@ assert n_abs == n;
    if (n < 0) {
        n_abs = -n;
    }
    //@ assert n_abs == abs_val(n);

    div = 0;
    temp = n_abs;
    /*@
        loop invariant 0 <= temp <= n_abs;
        loop invariant 0 <= div <= n_abs / 10;
        loop invariant temp == n_abs - 10 * div;
        loop assigns temp, div;
    */
    while (temp >= 10) {
        //@ assert temp >= 10;
        temp -= 10;
        div += 1;
        //@ assert temp == n_abs - 10 * div;
    }

    mod_res = n_abs;
    /*@
        loop invariant 0 <= mod_res <= n_abs;
        loop invariant mod_res == n_abs - 10 * division_part(n_abs, mod_res);
        loop assigns mod_res;
    */
    while (mod_res >= 10) {
        //@ assert mod_res >= 10;
        mod_res -= 10;
        //@ assert mod_res == n_abs - 10 * division_part(n_abs, mod_res);
    }

    //@ assert div == n_abs / 10;
    //@ assert mod_res == n_abs % 10;
    return div == 9 || mod_res == 9;
}

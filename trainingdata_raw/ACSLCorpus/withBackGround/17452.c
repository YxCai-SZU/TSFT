#include <stdbool.h>

/*@
    predicate is_mod_eq(integer n, integer m) =
        n % 1000 == m % 1000;

    lemma mod_preservation:
        \forall integer n, m;
            m >= 1000 && is_mod_eq(n, m) ==>
            is_mod_eq(n, m - 1000);
*/

/*@
    requires 1 <= n <= 10000;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> n % 1000 != 0;
    ensures \result == 1 ==> n % 1000 == 0;
*/
int func(int n) {
    int m;
    int result;

    m = n;
    /*@
        loop invariant 0 <= m <= n;
        loop invariant is_mod_eq(n, m);
        loop assigns m;
    */
    while (m >= 1000) {
        //@ assert m >= 1000;
        m = m - 1000;
    }

    //@ assert m >= 0 && m < 1000;
    //@ assert is_mod_eq(n, m);

    if (m == 0) {
        //@ assert n % 1000 == 0;
        result = 1;
    } else {
        //@ assert n % 1000 != 0;
        result = 0;
    }

    return result;
}

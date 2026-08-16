#include <stdbool.h>

/*@
    predicate is_mod_equal(integer a, integer b, integer mod) =
        a % mod == b % mod;

    lemma mod_preservation:
        \forall integer b, integer b_mod_2;
        0 <= b_mod_2 <= b && is_mod_equal(b_mod_2, b, 2) ==>
        (b_mod_2 - 2 >= 0 ==> is_mod_equal(b_mod_2 - 2, b, 2));
*/

/*@
    requires 1 <= a <= 100;
    requires 0 <= b <= a;
    ensures \result == (b % 2 == 0 && a >= b);
*/
bool func(int a, int b) {
    int b_mod_2;
    b_mod_2 = b;

    /*@
        loop invariant 0 <= b_mod_2 <= b;
        loop invariant b_mod_2 <= a;
        loop invariant b_mod_2 % 2 == b % 2;
        loop assigns b_mod_2;
    */
    while (b_mod_2 >= 2) {
        //@ assert b_mod_2 % 2 == b % 2;
        b_mod_2 -= 2;
    }

    //@ assert b_mod_2 == b % 2;
    return b_mod_2 == 0 && a >= b;
}

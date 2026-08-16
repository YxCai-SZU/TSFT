#include <stdbool.h>

/*@
    predicate is_mod(integer a, integer b, integer m) =
        a >= 0 && b >= 0 && m >= 0 && m < 3 && a % 3 == m && b % 3 == m;
*/

/*@
    lemma mod_property:
        \forall integer a, b;
            1 <= a <= 100 && 1 <= b <= 100 ==>
            (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) ==>
            (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/
bool func(int a, int b) {
    int mod_3_a;
    int mod_3_b;
    int mod_3_sum;
    bool is_a_multiple_of_3;
    bool is_b_multiple_of_3;
    bool is_sum_multiple_of_3;
    bool res;
    int tmp;

    // Compute a % 3
    tmp = a;
    /*@
        loop invariant 0 <= tmp <= a;
        loop invariant is_mod(a, tmp, a % 3);
        loop assigns tmp;
    */
    while (tmp >= 3) {
        tmp -= 3;
    }
    mod_3_a = tmp;

    // Compute b % 3
    tmp = b;
    /*@
        loop invariant 0 <= tmp <= b;
        loop invariant is_mod(b, tmp, b % 3);
        loop assigns tmp;
    */
    while (tmp >= 3) {
        tmp -= 3;
    }
    mod_3_b = tmp;

    // Compute (a + b) % 3
    tmp = a + b;
    /*@
        loop invariant 0 <= tmp <= a + b;
        loop invariant is_mod(a + b, tmp, (a + b) % 3);
        loop assigns tmp;
    */
    while (tmp >= 3) {
        tmp -= 3;
    }
    mod_3_sum = tmp;

    is_a_multiple_of_3 = (mod_3_a == 0);
    is_b_multiple_of_3 = (mod_3_b == 0);
    is_sum_multiple_of_3 = (mod_3_sum == 0);
    res = is_a_multiple_of_3 || is_b_multiple_of_3 || is_sum_multiple_of_3;

    //@ assert res == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);

    return res;
}

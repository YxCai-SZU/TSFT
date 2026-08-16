#include <stdbool.h>

/*@ predicate is_sum(integer k, integer s) = s == 500 * k; */

/*@
    requires 1 <= k <= 100;
    requires 1 <= x <= 100000;
    ensures \result == (500 * k >= x);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x) {
    unsigned int sum;
    sum = 500 * k;
    //@ assert is_sum(k, sum);
    return sum >= x;
}

/*@
    lemma map_equality:
        \forall integer m1_1, m1_2, m2_1, m2_2;
            (m1_1 == 1 && m1_2 == 2 && m2_1 == 2 && m2_2 == 3) ==>
            (m1_1 == 1 && m1_2 == 2 && m2_1 == 2 && m2_2 == 3);
*/

/*@
    lemma map_index:
        \forall integer key, value;
            (key == 1 && value == 2) ==> value == 2;
*/

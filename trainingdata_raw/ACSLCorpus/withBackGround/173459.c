#include <stdint.h>

/*@ predicate a_in_range(integer a) = 2 <= a && a <= 100; */
/*@ predicate b_in_range(integer b) = 2 <= b && b <= 100; */

/*@ logic integer compute_result(integer a, integer b) = (a - 1) * (b - 1); */

/*@ lemma no_underflow_a: \forall integer a; a_in_range(a) ==> a - 1 >= 1; */
/*@ lemma no_underflow_b: \forall integer b; b_in_range(b) ==> b - 1 >= 1; */
/*@ lemma result_bound: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> compute_result(a, b) <= 99 * 99; */

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t res;
    
    //@ assert a - 1 >= 1;
    //@ assert b - 1 >= 1;
    //@ assert (a - 1) * (b - 1) <= 99 * 99;
    
    res = (a - 1) * (b - 1);
    
    //@ assert res == compute_result(a, b);
    return res;
}

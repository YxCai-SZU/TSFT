#include <stdint.h>

/*@ predicate valid_range(integer a) = 2 <= a && a <= 100; */

/*@
    lemma subtraction_safe:
        \forall integer a, b; valid_range(a) && valid_range(b) ==> 
        a - 1 >= 1 && b - 1 >= 1;
*/

/*@
    lemma multiplication_bound:
        \forall integer a, b; valid_range(a) && valid_range(b) ==> 
        (a - 1) * (b - 1) <= 99 * 99;
*/

/*@
    requires valid_range(A) && valid_range(B);
    ensures \result == (A - 1) * (B - 1);
    assigns \nothing;
*/
int32_t func(int32_t A, int32_t B) {
    int32_t res;
    
    //@ assert A - 1 >= 1;
    //@ assert B - 1 >= 1;
    //@ assert (A - 1) * (B - 1) <= 99 * 99;
    
    res = (A - 1) * (B - 1);
    return res;
}

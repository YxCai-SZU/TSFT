#include <limits.h>

/*@
    predicate is_positive(integer a) = a > 0;
    predicate no_overflow(integer a) = a <= INT_MAX / 5;
*/

/*@
    logic integer perimeter_pentagon_logic(integer a) = a * 5;
*/

/*@
    lemma overflow_prevention: 
        \forall integer a; 
        is_positive(a) && no_overflow(a) ==> perimeter_pentagon_logic(a) <= INT_MAX;
*/

/*@
    requires is_positive(a) && no_overflow(a);
    ensures \result == perimeter_pentagon_logic(a);
    ensures is_positive(\result);
    assigns \nothing;
*/
int perimeter_pentagon(int a) {
    //@ assert is_positive(a) && no_overflow(a);
    //@ assert perimeter_pentagon_logic(a) <= INT_MAX;
    return a * 5;
}

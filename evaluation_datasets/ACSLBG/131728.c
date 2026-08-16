#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 0 <= a && a < 1000;
    predicate b_in_range(integer b) = 0 <= b && b < 1000;
    predicate result_bounded(integer r) = r <= 1000;
    predicate result_correct(integer a, integer b, integer r) = 
        r == (a + b + 1) / 2;
*/

/*@
    logic integer sum_plus_one(integer a, integer b) = a + b + 1;
    
    lemma sum_bound: 
        \forall integer a, b; 
        a_in_range(a) && b_in_range(b) ==> sum_plus_one(a, b) <= 1999;
*/


uint64_t func(uint64_t a, uint64_t b) {
    // Declare all variables at the top
    uint64_t result;
    
    //@ assert a_in_range(a) && b_in_range(b);
    //@ assert sum_plus_one(a, b) <= 1999;
    
    result = (a + b + 1) / 2;
    
    //@ assert result_bounded(result);
    //@ assert result_correct(a, b, result);
    
    return result;
}

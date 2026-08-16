#include <stdint.h>

/*@ predicate valid_range(integer x) = 1 <= x <= 3; */
/*@ predicate distinct(integer x, integer y) = x != y; */
/*@ logic integer compute_result(integer a, integer b) = 6 - a - b; */

/*@ lemma result_bounds: 
      \forall integer a, b; 
      valid_range(a) && valid_range(b) && distinct(a,b) ==> 
      1 <= compute_result(a,b) <= 3; */

/*@ lemma result_distinct_a: 
      \forall integer a, b; 
      valid_range(a) && valid_range(b) && distinct(a,b) ==> 
      compute_result(a,b) != a; */

/*@ lemma result_distinct_b: 
      \forall integer a, b; 
      valid_range(a) && valid_range(b) && distinct(a,b) ==> 
      compute_result(a,b) != b; */

/*@ lemma no_overflow: 
      \forall integer a, b; 
      valid_range(a) && valid_range(b) ==> 6 >= a + b; */

/*@ requires 1 <= a <= 3;
    @ requires 1 <= b <= 3;
    @ requires a != b;
    @ ensures \result == 6 - a - b;
    @ ensures 1 <= \result <= 3;
    @ ensures \result != a;
    @ ensures \result != b;
    @*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t result;
    
    //@ assert 6 >= a + b;
    
    result = 6 - a - b;
    
    //@ assert result == 6 - a - b;
    //@ assert 1 <= result <= 3;
    //@ assert result != a;
    //@ assert result != b;
    
    return result;
}

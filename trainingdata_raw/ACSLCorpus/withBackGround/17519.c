#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_range(integer x) = 1 <= x <= 3; */

/*@ predicate distinct(integer a, integer b) = a != b; */

/*@ logic integer compute_result(integer a, integer b) = 6 - a - b; */

/*@ lemma result_in_range: 
      \forall integer a, b; 
      valid_range(a) && valid_range(b) && distinct(a,b) ==> 
      1 <= compute_result(a,b) <= 3; */

/*@ requires 1 <= a <= 3;
    @ requires 1 <= b <= 3;
    @ requires a != b;
    @ ensures \result == 6 - a - b;
    @ ensures 1 <= \result <= 3;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t result;
    
    if (a == 1) {
        if (b == 2) {
            result = 3;
        } else {
            result = 2;
        }
    } else if (a == 2) {
        if (b == 1) {
            result = 3;
        } else {
            result = 1;
        }
    } else {
        if (b == 1) {
            result = 2;
        } else {
            result = 1;
        }
    }
    
    //@ assert result == 6 - a - b;
    
    return result;
}

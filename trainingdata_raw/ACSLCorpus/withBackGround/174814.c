#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = 1 <= x <= 100; */

/*@ predicate result_candidate(integer a, integer b, integer c, integer r) =
    r == a + b + 1 || r == a + c + 1 || r == b + c + 1; */

/*@ lemma result_ge_three: 
    \forall integer a, b, c, r; 
    is_valid_range(a) && is_valid_range(b) && is_valid_range(c) && 
    result_candidate(a, b, c, r) ==> r >= 3; */

/*@ requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    ensures result_candidate(a, b, c, \result);
    ensures \result >= 3;
    assigns \nothing;
*/
int func(int a, int b, int c) {
    int result = 0;
    
    if (a > b) {
        if (a > c) {
            result = a + c + 1;
        } else {
            result = a + b + 1;
        }
    } else {
        if (b > c) {
            result = a + b + 1;
        } else {
            result = a + c + 1;
        }
    }
    
    //@ assert result == a + b + 1 || result == a + c + 1 || result == b + c + 1;
    //@ assert result >= 3;
    
    return result;
}

#include <stdbool.h>

/*@ predicate is_valid_range(integer a, integer b) =
      1 <= a <= 100 && 1 <= b <= 100;
*/

/*@ logic integer double_val(integer x) = x * 2; */

/*@ lemma double_range: \forall integer a, b; 
      is_valid_range(a, b) ==> 
      2 <= double_val(a) <= 200 && 2 <= double_val(b) <= 200;
*/

/*@ requires is_valid_range(a, b);
    ensures \result == (double_val(a) >= b && double_val(b) >= a);
    assigns \nothing;
*/
bool func(int a, int b) {
    bool is_a_valid = false;
    bool is_b_valid = false;
    
    //@ assert is_valid_range(a, b);
    
    if (a * 2 >= b) {
        is_a_valid = true;
    }
    
    if (b * 2 >= a) {
        is_b_valid = true;
    }
    
    if (is_a_valid && is_b_valid) {
        //@ assert double_val(a) >= b && double_val(b) >= a;
        return true;
    } else {
        //@ assert !(double_val(a) >= b && double_val(b) >= a);
        return false;
    }
}

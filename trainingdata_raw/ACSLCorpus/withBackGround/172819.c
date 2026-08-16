#include <limits.h>

/*@ predicate is_sum_of_two(integer a, integer b, integer c, integer d, integer result) =
    result == a + b || result == a + c || result == a + d ||
    result == b + c || result == b + d || result == c + d;
*/

/*@ lemma sum_bounds:
    \forall integer a, b, c, d;
    -100 <= a <= 100 && -100 <= b <= 100 && -100 <= c <= 100 && -100 <= d <= 100 ==>
    -200 <= a + b <= 200 && -200 <= a + c <= 200 && -200 <= a + d <= 200 &&
    -200 <= b + c <= 200 && -200 <= b + d <= 200 && -200 <= c + d <= 200;
*/

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    requires -100 <= d <= 100;
    ensures \result == a + b || \result == a + c || \result == a + d ||
            \result == b + c || \result == b + d || \result == c + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_value;
    int temp_value;
    
    //@ assert -200 <= a + b <= 200;
    max_value = a + b;
    
    //@ assert -200 <= a + c <= 200;
    temp_value = a + c;
    if (temp_value > max_value) {
        max_value = temp_value;
    }
    
    //@ assert -200 <= a + d <= 200;
    temp_value = a + d;
    if (temp_value > max_value) {
        max_value = temp_value;
    }
    
    //@ assert -200 <= b + c <= 200;
    temp_value = b + c;
    if (temp_value > max_value) {
        max_value = temp_value;
    }
    
    //@ assert -200 <= b + d <= 200;
    temp_value = b + d;
    if (temp_value > max_value) {
        max_value = temp_value;
    }
    
    //@ assert -200 <= c + d <= 200;
    temp_value = c + d;
    if (temp_value > max_value) {
        max_value = temp_value;
    }
    
    //@ assert is_sum_of_two(a, b, c, d, max_value);
    return max_value;
}

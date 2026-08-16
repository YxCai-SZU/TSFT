#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate x_in_range(integer x) = 1 <= x <= 200;
    predicate sum_in_range(integer a, integer b) = 1 <= a + b <= 200;
*/

/*@
    requires a_in_range(a) && b_in_range(b) && x_in_range(x);
    ensures \result == (a <= x && a + b >= x);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long x) {
    // Variable declarations at scope top
    bool and_result;
    
    // Precondition assertions
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= x <= 200;
    
    // Overflow safety
    //@ assert a + b <= 200;
    //@ assert a + b >= 1;
    
    if (a <= x) {
        if (a + b >= x) {
            and_result = true;
        } else {
            and_result = false;
        }
    } else {
        and_result = false;
    }
    
    // Postcondition verification
    //@ assert and_result == (a <= x && a + b >= x);
    
    return and_result;
}

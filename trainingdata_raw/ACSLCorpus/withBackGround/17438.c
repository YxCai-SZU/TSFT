#include <stdbool.h>
#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 0 <= a <= 1000000000000000000;
    predicate b_in_range(integer b) = 0 <= b <= 1000000000000000000;
    predicate x_in_range(integer x) = 0 <= x <= 1000000000000000000;
    
    lemma sum_bounds:
        \forall integer a, b;
        a_in_range(a) && b_in_range(b) ==> a + b <= 18446744073709551615;
*/

/*@
    requires a_in_range(a) && b_in_range(b) && x_in_range(x);
    ensures \result == (a <= x && a + b >= x);
    assigns \nothing;
*/
bool func(uint64_t a, uint64_t b, uint64_t x) {
    bool result;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert x_in_range(x);
    
    //@ assert a + b <= 18446744073709551615;
    
    if (a <= x && a + b >= x) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == (a <= x && a + b >= x);
    return result;
}

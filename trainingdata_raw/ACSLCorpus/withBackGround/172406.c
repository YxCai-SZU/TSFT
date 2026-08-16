#include <stddef.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer avg_formula(integer a, integer b) = (a + b + 1) / 2;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == avg_formula(a, b);
    assigns \nothing;
*/
size_t func(size_t a, size_t b) {
    size_t sum;
    size_t avg;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    
    sum = a + b;
    //@ assert 2 <= sum <= 200;
    
    avg = (sum + 1) / 2;
    //@ assert 1 <= avg <= 100;
    
    return avg;
}

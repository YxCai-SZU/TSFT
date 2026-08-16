#include <stdbool.h>

/*@
    predicate in_range(integer v) = 0 <= v <= 100;
    predicate sum_in_range(integer a, integer b) = a + b <= 200;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(x);
    ensures \result == (x >= a && x <= a + b);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x) {
    unsigned long long max_val;
    unsigned long long min_val;
    
    //@ assert in_range(a) && in_range(b);
    //@ assert sum_in_range(a, b);
    
    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }
    
    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }
    
    if (x < a || x > a + b) {
        return false;
    } else {
        //@ assert x >= a && x <= a + b;
        return true;
    }
}

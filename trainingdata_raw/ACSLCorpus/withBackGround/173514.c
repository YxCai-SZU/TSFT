#include <stdbool.h>

/*@ predicate in_range(integer x) = 1 <= x <= 100; */

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == true <==> (c <= b && b <= d) || (c <= a && a <= d);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    bool result;
    
    if ((c <= b && b <= d) || (c <= a && a <= d)) {
        result = true;
    } else {
        //@ assert !(c <= b && b <= d) && !(c <= a && a <= d);
        result = false;
    }
    
    return result;
}

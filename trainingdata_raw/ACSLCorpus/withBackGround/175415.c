#include <stdbool.h>

/*@
    predicate in_range(integer x) = 1 <= x && x <= 100;
    predicate product_in_range(integer x, integer y) = x * y <= 10000;
*/

/*@
    requires in_range(x) && in_range(y);
    ensures \result == (x * y <= 10000);
    assigns \nothing;
*/
bool check_nonlinear(unsigned int x, unsigned int y) {
    // Variable declarations at top of scope
    bool result;
    
    // Main verification property
    //@ assert x * y <= 10000;
    
    result = (x * y <= 10000);
    return result;
}

int main() {
    return 0;
}

#include <stdbool.h>

/*@ predicate is_burst(integer a, integer b, integer c) = a + b + c >= 22; */

/*@
    requires 1 <= a <= 13;
    requires 1 <= b <= 13;
    requires 1 <= c <= 13;
    ensures \result == true <==> a + b + c >= 22;
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int sum;
    bool is_burst_var;
    
    sum = a + b + c;
    is_burst_var = false;
    
    if (sum >= 22) {
        is_burst_var = true;
    }
    
    if (is_burst_var) {
        //@ assert a + b + c >= 22;
        return true;
    } else {
        //@ assert a + b + c < 22;
        return false;
    }
}

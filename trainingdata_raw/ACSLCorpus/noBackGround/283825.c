#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures \result == (n == m);
    assigns \nothing;
*/
bool input_tuple(unsigned int n, unsigned int m) {
    bool result;
    
    //@ assert n == m ==> n == m;
    
    result = (n == m);
    return result;
}

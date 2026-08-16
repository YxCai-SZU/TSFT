#include <stdbool.h>

/*@
    requires 1 <= n <= 10000;
    requires 0 <= a <= 1000;
    ensures \result == (n % 500 <= a);
*/
bool func(unsigned long n, unsigned long a) {
    unsigned long r;
    bool result;
    
    r = n % 500;
    
    //@ assert (0 <= (r) <= 500);
    
    if (r <= a) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}

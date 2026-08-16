#include <stddef.h>

/*@ requires 1 <= n <= 100;
    ensures \result == n * n;
    assigns \nothing;
*/
unsigned int func(unsigned int n) {
    unsigned int res;
    
    //@ assert 1 <= n && n <= 100;
    //@ assert n * n <= 10000;
    
    res = n * n;
    return res;
}

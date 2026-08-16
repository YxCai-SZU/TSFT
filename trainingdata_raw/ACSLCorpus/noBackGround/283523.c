#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t a) {
    int64_t nn;
    int64_t result;

    //@ assert n * n <= 10000;
    nn = n * n;
    
    //@ assert 0 <= n * n - a <= 10000;
    //@ assert nn - a == n * n - a;
    
    result = nn - a;
    return result;
}

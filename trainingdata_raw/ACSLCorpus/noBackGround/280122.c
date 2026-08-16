#include <stdint.h>
/*@
    requires (1 <= (n) && (n) <= 100000 &&
        (n) <= (m) && (m) <= 100000000000000000);
    ensures \result >= 0;
    ensures \result <= n;
    ensures \result == n - (m - 1) || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    int64_t x;
    //@ assert (1 <= (n) && (n) <= 100000 &&         (n) <= (m) && (m) <= 100000000000000000);
    
    if (n > m - 1) {
        x = n - (m - 1);
    } else {
        x = 0;
    }
    
    //@ assert x >= 0;
    //@ assert x <= n;
    //@ assert x == n - (m - 1) || x == 0;
    
    return x;
}

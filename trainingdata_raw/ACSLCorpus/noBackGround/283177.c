#include <stddef.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (d) <= 20);
    ensures \result <= n;
    ensures \result >= 0;
    assigns \nothing;
*/
size_t func(size_t n, size_t d) {
    size_t x;
    size_t ans;
    
    //@ assert (1 <= (n) <= 20 && 1 <= (d) <= 20);
    
    x = d * 2 + 1;
    //@ assert x == ((d) * 2 + 1);
    
    ans = n / x;
    //@ assert ans == n / ((d) * 2 + 1);
    
    //@ assert ans <= n;
    //@ assert ans >= 0;
    
    return ans;
}

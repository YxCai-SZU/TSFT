#include <stdint.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == ((((n)) * 800) - ((((n)) / 15) * 200));
    assigns \nothing;
*/
int32_t func(uint32_t n) {
    int32_t x = 800;
    int32_t y = 200;
    int32_t ans = 0;
    uint32_t i = 0;
    
    //@ assert (1 <= (n) <= 100);
    //@ assert ((n) * 800) <= 80000;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ans == i * x;
        loop invariant ans <= ((n) * 800);
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        ans += x;
        i += 1;
    }
    
    //@ assert ans == ((n) * 800);
    
    i = 0;
    uint32_t limit = n / 15;
    
    //@ assert limit <= 6;
    
    /*@
        loop invariant 0 <= i <= limit;
        loop invariant ans == ((n) * 800) - i * y;
        loop invariant ans <= ((n) * 800);
        loop assigns i, ans;
        loop variant limit - i;
    */
    while (i < limit) {
        ans -= y;
        i += 1;
    }
    
    //@ assert ans == ((((n)) * 800) - ((((n)) / 15) * 200));
    return ans;
}

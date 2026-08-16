#include <stdint.h>

/*@
    requires (1 <= (x) <= 1000000000000000);
    ensures \result >= ((((x)) / 11) * 2);
    ensures \result <= ((((x)) / 11) * 2 + 2);
    assigns \nothing;
*/
uint64_t func(uint64_t x) {
    uint64_t q;
    uint64_t r;
    uint64_t ans;
    
    q = x / 11;
    r = x % 11;
    ans = q * 2;
    
    //@ assert q == ((x) / 11);
    //@ assert r == ((x) % 11);
    //@ assert ans == ((((x)) / 11) * 2);
    
    if (r > 6) {
        ans += 2;
        //@ assert ans == ((((x)) / 11) * 2) + 2;
    } else {
        ans += 1;
        //@ assert ans == ((((x)) / 11) * 2) + 1;
    }
    
    //@ assert ans >= ((((x)) / 11) * 2);
    //@ assert ans <= ((((x)) / 11) * 2 + 2);
    
    return ans;
}

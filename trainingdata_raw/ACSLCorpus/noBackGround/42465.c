#include <stdbool.h>
#include <stdint.h>

/*@ requires (2 <= (n) && (n) <= 100000);
    requires \valid(an + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((an)[i]) && ((an)[i]) <= 1000000000));
    assigns \nothing;
    ensures 0 <= \result <= n;
 */
int32_t func(uint32_t n, const int64_t *an) {
    int32_t ans = 0;
    uint32_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant ans >= 0;
        loop invariant ans <= i;
        loop invariant (2 <= (n) && (n) <= 100000);
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((an)[i]) && ((an)[i]) <= 1000000000));
        loop assigns i, ans;
        loop variant n - i;
     */
    while (i < n) {
        int64_t x = an[i];
        
        //@ assert (1 <= (x) && (x) <= 1000000000);
        
        if (x & 1) {
            ans += 1;
        }
        
        i += 1;
    }
    
    //@ assert 0 <= ans <= n;
    return ans;
}

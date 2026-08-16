#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 200000 &&
        1 <= (k) && (k) <= (n) &&
        1 <= (a) && (a) <= 1000000000 &&
        1 <= (b) && (b) <= 1000000000);
    requires \valid(p + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= 1000000000);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int64_t func(int64_t n, int64_t k, int64_t a, int64_t b, int64_t *p) {
    int64_t ans = 0;
    int64_t i = 0;
    uint64_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= i <= index;
        loop invariant 0 <= ans <= index;
        loop assigns ans, i, index;
        loop variant n - index;
    */
    while (index < (uint64_t)n) {
        int64_t item = p[index];
        
        if (k + a < item) {
            ans += 1;
        } else if (k + a == item) {
            ans += 1;
        } else {
            if (a < item) {
                ans += 1;
            }
        }
        
        index += 1;
    }
    
    return ans;
}

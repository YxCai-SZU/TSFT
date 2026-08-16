#include <limits.h>

/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) &&
        1 <= (k) && (k) <= (a) + (b) + (c) &&
        (k) <= 2000000000);
    ensures \result >= -k && \result <= k;
    assigns \nothing;
*/
int func(int a, int b, int c, int k) {
    int ans;
    int rst;
    
    ans = 0;
    rst = k;
    
    //@ assert (0 <= (a) && 0 <= (b) && 0 <= (c) &&         1 <= (k) && (k) <= (a) + (b) + (c) &&         (k) <= 2000000000);
    
    if (a >= rst) {
        ans += rst;
        rst = 0;
    } else {
        ans += a;
        rst -= a;
    }
    
    //@ assert -k <= ans <= k;
    
    if (b >= rst) {
        rst = 0;
    } else {
        rst -= b;
    }
    
    //@ assert 0 <= rst <= k;
    
    ans -= rst;
    
    //@ assert ans >= -k;
    
    return ans;
}

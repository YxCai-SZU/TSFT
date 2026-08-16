#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result >= 0;
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    int ans;
    
    if (a < b) {
        ans = a;
    } else {
        ans = b;
    }
    
    //@ assert ans <= a && ans <= b;
    
    if (ans < c) {
        /* skip */
    } else {
        ans = c;
    }
    
    //@ assert ans <= a && ans <= b && ans <= c;
    
    if (ans < d) {
        /* skip */
    } else {
        ans = d;
    }
    
    //@ assert ans <= a;
    
    return ans;
}

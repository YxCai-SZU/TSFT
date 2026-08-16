#include <stdbool.h>

/*@
    requires 1 <= n <= 1000000;
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n) {
    int ans = 0;
    int i = 1;
    
    /*@
        loop invariant 1 <= i;
        loop invariant i <= n + 1;
        loop invariant ans >= 0;
        loop invariant ans <= i - 1;
        loop invariant ans <= n;
        loop assigns i, ans;
        loop variant n - i + 1;
    */
    while (i <= n) {
        bool divisible = false;
        int j = 1;
        
        /*@
            loop invariant 1 <= j;
            loop invariant j <= i + 1;
            loop assigns j, divisible;
            loop variant i - j + 1;
        */
        while (j <= i) {
            //@ assert 1 <= n <= 1000000;
            //@ assert 1 <= i <= n;
            if (i == j) {
                divisible = true;
                break;
            }
            j += 1;
        }
        
        if (divisible) {
            ans += 1;
        }
        
        i += 1;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= n;
    return ans;
}

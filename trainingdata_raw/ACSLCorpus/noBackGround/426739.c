#include <stdbool.h>

/*@
    requires 1 <= n <= 10000;
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n) {
    int i = 0;
    int ans = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 1 <= n <= 10000;
        loop invariant ((ans) >= 0 && (ans) <= (i));
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert ((ans) >= 0 && (ans) <= (i));
        
        bool divisible = false;
        int j = 1;
        
        /*@
            loop invariant 1 <= j <= 10;
            loop invariant 1 <= n <= 10000;
            loop assigns j, divisible;
            loop variant 10 - j;
        */
        while (j < 10) {
            int k = 1;
            
            /*@
                loop invariant 1 <= k <= 10;
                loop invariant 1 <= n <= 10000;
                loop assigns k, divisible;
                loop variant 10 - k;
            */
            while (k < 10) {
                int l = 1;
                
                /*@
                    loop invariant 1 <= l <= 10;
                    loop invariant 1 <= n <= 10000;
                    loop assigns l, divisible;
                    loop variant 10 - l;
                */
                while (l < 10) {
                    int sum = j + k + l;
                    if (sum == i) {
                        divisible = true;
                        break;
                    }
                    l += 1;
                }
                if (divisible) {
                    break;
                }
                k += 1;
            }
            if (divisible) {
                break;
            }
            j += 1;
        }
        
        if (divisible) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}

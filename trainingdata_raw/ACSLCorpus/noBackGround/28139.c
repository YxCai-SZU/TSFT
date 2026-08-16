#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 100000 &&
    (k) >= 1 && (k) <= 500 &&
    \valid((h) + (0 .. (n)-1)) &&
    \forall integer j; 0 <= j < (n) ==> (h)[j] >= 1 && (h)[j] <= 500);
    ensures ((\result) >= 0 && (\result) <= (n));
    assigns \nothing;
*/
long func(long n, long k, const long *h) {
    long ans;
    long i;
    
    ans = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ((ans) >= 0 && (ans) <= (i));
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        
        if (h[i] >= k) {
            ans = ans + 1;
        }
        
        i = i + 1;
    }
    
    return ans;
}

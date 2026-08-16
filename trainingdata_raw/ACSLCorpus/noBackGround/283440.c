#include <stdint.h>
#include <limits.h>

/*@
    requires ((n) >= 2 && (n) <= 100 &&
    \valid((w) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (w)[i] >= 1 && (w)[i] <= 100);
    ensures ((\result) >= 0);
    assigns \nothing;
*/
int64_t func(uint32_t n, const int64_t *w) {
    int64_t ans = INT64_MAX;
    uint32_t t = 1;
    
    /*@ loop invariant 1 <= t <= n;
        loop invariant ((n) >= 2 && (n) <= 100 &&
    \valid((w) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (w)[i] >= 1 && (w)[i] <= 100);
        loop invariant ((ans) >= 0);
        loop assigns ans, t;
        loop variant n - t;
    */
    while (t < n) {
        int64_t s1 = 0;
        uint32_t i = 0;
        
        /*@ loop invariant 0 <= i <= t;
            loop invariant ((n) >= 2 && (n) <= 100 &&
    \valid((w) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (w)[i] >= 1 && (w)[i] <= 100);
            loop invariant s1 >= 0;
            loop invariant s1 <= (int64_t)i * 100;
            loop assigns s1, i;
            loop variant t - i;
        */
        while (i < t) {
            //@ assert 0 <= i < n;
            s1 += w[i];
            i++;
        }
        
        int64_t s2 = 0;
        uint32_t j = t;
        
        /*@ loop invariant t <= j <= n;
            loop invariant ((n) >= 2 && (n) <= 100 &&
    \valid((w) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (w)[i] >= 1 && (w)[i] <= 100);
            loop invariant s2 >= 0;
            loop invariant s2 <= (int64_t)(j - t) * 100;
            loop assigns s2, j;
            loop variant n - j;
        */
        while (j < n) {
            //@ assert 0 <= j < n;
            s2 += w[j];
            j++;
        }
        
        int64_t diff = s1 - s2;
        if (diff < 0) {
            diff = -diff;
        }
        
        if (ans > diff) {
            ans = diff;
        }
        
        t++;
    }
    
    //@ assert ((ans) >= 0);
    return ans;
}

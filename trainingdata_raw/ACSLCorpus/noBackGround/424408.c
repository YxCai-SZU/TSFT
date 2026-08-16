#include <stdint.h>
#include <limits.h>

/*@
    requires ((n) > 0 && (n) <= 100000 &&
        \valid((h) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> 1 <= (h)[j] <= 1000000000);
    ensures \result >= 0;
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t *h) {
    int32_t tmp;
    int32_t max;
    int32_t i;
    
    tmp = INT_MAX;
    max = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= n-1;
        loop invariant tmp >= 0;
        loop invariant max >= 0;
        loop invariant tmp <= INT_MAX;
        loop invariant \forall integer k; 0 <= k < i ==> ((k) >= (n)-1 ? INT_MAX :
        ((h)[(k)] > (h)[(k)+1] ? (h)[(k)] - (h)[(k)+1] : 0)) >= tmp;
        loop invariant \forall integer k; 0 <= k < i ==> max >= ((k) >= (n)-1 ? INT_MAX :
        ((h)[(k)] > (h)[(k)+1] ? (h)[(k)] - (h)[(k)+1] : 0));
        loop assigns i, tmp, max;
        loop variant n - i;
    */
    while (i < n - 1) {
        int32_t diff;
        
        //@ assert 0 <= i < n-1;
        
        if (h[i] > h[i + 1]) {
            diff = h[i] - h[i + 1];
        } else {
            diff = 0;
        }
        
        //@ assert diff == ((i) >= (n)-1 ? INT_MAX :         ((h)[(i)] > (h)[(i)+1] ? (h)[(i)] - (h)[(i)+1] : 0));
        
        if (diff < tmp) {
            tmp = diff;
        }
        
        //@ assert tmp >= 0;
        
        if (diff > max) {
            max = diff;
        }
        
        //@ assert max >= 0;
        
        i = i + 1;
    }
    
    return max;
}

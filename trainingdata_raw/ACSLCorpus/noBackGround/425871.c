#include <stdint.h>
#include <stdbool.h>

/*@ requires n > 0 && k > 0;
    requires ((n) > 0 &&
    \forall integer j; 0 <= j < (n) ==> (((h)[j]) > 0));
    requires \valid(h+(0..n-1));
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t k, uint32_t *h) {
    uint32_t ans = 0;
    uint32_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant ans >= 0;
        loop invariant ans <= i;
        loop invariant n > 0 && k > 0;
        loop invariant ((n) > 0 &&
    \forall integer j; 0 <= j < (n) ==> (((h)[j]) > 0));
        loop invariant \forall integer j; 0 <= j < i ==> (h[j] >= k ==> ans >= 1);
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (h[i] >= k) {
            //@ assert h[i] >= k;
            ans += 1;
        }
        i += 1;
        //@ assert ans <= i;
    }
    //@ assert ans <= n;
    return ans;
}

#include <stdbool.h>
#include <stdint.h>

/*@
    requires n >= 1 && n <= 100000;
    requires k >= 1 && k <= 500;
    requires \valid(h + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= h[i] <= 500;
    assigns \nothing;
    ensures \result >= 0 && \result <= n;
    ensures \forall integer i; 0 <= i < n ==> (h[i] >= k ==> \result > 0);
*/
uint32_t func(uint32_t n, uint32_t k, uint32_t *h) {
    uint32_t ans = 0;
    uint32_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant ans >= 0;
        loop invariant ans <= index;
        loop invariant ans <= n;
        loop invariant \forall integer j; 0 <= j < index ==> (h[j] >= k ==> ans > 0);
        loop assigns ans, index;
        loop variant n - index;
    */
    while (index < n) {
        uint32_t hi = h[index];
        if (hi >= k) {
            ans += 1;
        }
        index += 1;
    }
    return ans;
}

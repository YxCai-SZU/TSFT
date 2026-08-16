#include <stdbool.h>
#include <stdint.h>

/*@ requires n >= 1 && n <= 100000;
    requires k >= 1 && k <= 500;
    requires ((n) >= 1 && (n) <= 100000 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (h)[i] && (h)[i] <= 500);
    ensures ((\result) <= (n) &&
      \forall integer i; 0 <= i < (n) ==> ((h)[i] >= (k) ==> (\result) > 0));
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t k, uint32_t *h) {
    uint32_t ans = 0;
    uint32_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= ans <= i;
        loop invariant ((n) >= 1 && (n) <= 100000 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (h)[i] && (h)[i] <= 500);
        loop invariant i > 0 ==> \forall integer j; 0 <= j < i ==> (h[j] >= k ==> ans > 0);
        loop invariant ans <= i;
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (h[i] >= k) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}

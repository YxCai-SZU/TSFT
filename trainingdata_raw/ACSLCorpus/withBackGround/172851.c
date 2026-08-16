#include <stdint.h>
#include <stdbool.h>

/*@
    predicate valid_array(int32_t *a, integer n) =
        n >= 1 && n <= 200000 &&
        \valid(a + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 1000000000;
*/

/*@
    requires n >= 1 && n <= 200000;
    requires \valid(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 1000000000;
    ensures \result >= 0 || \result == -1;
    assigns \nothing;
*/
int32_t func(uint32_t n, int32_t *a) {
    int32_t ans = 0;
    uint32_t cnt = 0;
    uint32_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ans >= 0;
        loop invariant ans <= (int32_t)i;
        loop invariant cnt >= 0 && cnt <= 1000000000;
        loop invariant valid_array(a, n);
        loop assigns i, ans, cnt;
        loop variant n - i;
    */
    while (i < n) {
        if (cnt == a[i]) {
            ans += 1;
            cnt = 0;
        } else {
            cnt = a[i];
        }
        i += 1;
    }
    
    if (cnt != 0) {
        ans = -1;
    }
    
    return ans;
}

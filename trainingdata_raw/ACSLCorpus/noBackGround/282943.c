#include <stdint.h>
#include <limits.h>

/*@ requires n >= 1 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires \forall integer k; 0 <= k < n ==> 1 <= a[k] <= 100;
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t *a) {
    int64_t ans = INT64_MAX;
    int64_t i = 0;
    
    /*@ loop invariant 0 <= i <= 100;
        loop invariant ans >= 0;
        loop invariant ((n) >= 1 && (n) <= 100 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer k; 0 <= k < (n) ==> 1 <= (a)[k] <= 100);
        loop assigns i, ans;
        loop variant 100 - i;
    */
    while (i < 100) {
        int64_t x = 0;
        int64_t j = 0;
        
        /*@ loop invariant 0 <= j <= n;
            loop invariant 0 <= x <= j * 100;
            loop invariant ans >= 0;
            loop invariant ((n) >= 1 && (n) <= 100 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer k; 0 <= k < (n) ==> 1 <= (a)[k] <= 100);
            loop invariant 0 <= i && i < 100;
            loop assigns j, x;
            loop variant n - j;
        */
        while (j < n) {
            int64_t aat = a[j];
            int64_t diff = (aat > i) ? (aat - i) : (i - aat);
            x += diff;
            j++;
        }
        
        if (x < ans) {
            ans = x;
        }
        i++;
    }
    
    //@ assert ans >= 0;
    return ans;
}

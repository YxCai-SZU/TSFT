#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 2 && (n) <= 100000 &&
    \valid((h) + (0 .. (n)-1)) &&
    \forall integer j; 0 <= j < (n) ==> (h)[j] >= 1 && (h)[j] <= 10000);
    ensures \result >= 0 && \result <= (int)n;
    assigns \nothing;
*/
int func(size_t n, const int *h) {
    int cur_h = 0;
    int ans = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i && i <= n;
        loop invariant 0 <= ans && ans <= (int)i;
        loop invariant cur_h >= 0;
        loop invariant \forall integer j; 0 <= j < i ==> cur_h >= h[j];
        loop assigns i, cur_h, ans;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i && i < n;
        if (cur_h < h[i]) {
            cur_h = h[i];
            ans += 1;
        }
        i += 1;
    }
    return ans;
}

#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((n) > 0 && (k) > 0 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 0 < (a)[i] && (a)[i] <= (k));
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
size_t func(size_t n, size_t k, int* a) {
    size_t ans = 0;
    size_t i = 0;
    size_t cnt = 0;
    size_t half_k_val = k / 2;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= ans <= i;
        loop invariant cnt <= i;
        loop invariant ((n) > 0 && (k) > 0 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 0 < (a)[i] && (a)[i] <= (k));
        loop assigns i, cnt, ans;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (a[i] <= (int)half_k_val) {
            cnt++;
        }
        if (cnt >= 2) {
            ans++;
            cnt = 0;
        }
        i++;
    }
    return ans;
}

#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 100000 &&
    (k) >= 1 && (k) <= 500 &&
    \valid((hs) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (hs)[i] >= 1 && (hs)[i] <= 500);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(size_t n, size_t k, int *hs) {
    int ans = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ((ans) >= 0 && (ans) <= (i) && (i) <= (n));
        loop invariant ((n) >= 1 && (n) <= 100000 &&
    (k) >= 1 && (k) <= 500 &&
    \valid((hs) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (hs)[i] >= 1 && (hs)[i] <= 500);
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        int h = hs[i];
        //@ assert h >= 1 && h <= 500;
        if (h >= (int)k) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}

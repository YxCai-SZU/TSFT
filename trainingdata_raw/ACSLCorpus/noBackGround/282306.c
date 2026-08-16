#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((v) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (v)[i] >= 1 && (v)[i] <= 1000000000);
    ensures \result >= -1 && \result <= (int)n;
    assigns \nothing;
*/
int func(size_t n, const int *v) {
    int ans = 0;
    int p = 1000000000;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant ans >= 0;
        loop invariant ans <= (int)index;
        loop invariant p >= 1 && p <= 1000000000;
        loop assigns ans, p, index;
        loop variant n - index;
    */
    while (index < n) {
        int w = v[index];
        //@ assert w >= 1 && w <= 1000000000;

        if (w < p) {
            ans += 1;
            p = w;
        }
        index += 1;
    }

    if (ans == 0) {
        return -1;
    } else {
        return (int)n - ans;
    }
}

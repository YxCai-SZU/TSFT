#include <stddef.h>
#include <stdbool.h>

/*@
    requires (2 <= (n) <= 100000 &&
        \valid((h) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (h)[i] <= 10000);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int *h) {
    int mx = 0;
    int res = 0;
    size_t i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (n) &&
        0 <= (res) <= (i) &&
        (2 <= ((n)) <= 100000 &&
        \valid(((h)) + (0 .. ((n))-1)) &&
        \forall integer i; 0 <= i < ((n)) ==> 1 <= ((h))[i] <= 10000) &&
        \forall integer k; 0 <= k < (i) ==> (h)[k] <= (mx) &&
        (res) <= (n));
        loop assigns i, res, mx;
        loop variant n - i;
    */
    while (i < (size_t)n) {
        int e = h[i];
        if (e >= mx) {
            //@ assert e >= mx;
            res += 1;
            mx = e;
        }
        i += 1;
    }
    //@ assert 0 <= res <= n;
    return res;
}

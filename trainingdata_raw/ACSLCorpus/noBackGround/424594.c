#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 3 && (n) <= 200000 &&
        \valid((p) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(size_t n, const int *p) {
    int ans = 0;
    int min_bound = p[0];
    size_t i = 1;

    //@ ghost int *ghost_p = p;
    //@ ghost size_t ghost_n = n;

    /*@
        loop invariant 1 <= i <= n;
        loop invariant ans >= 0;
        loop invariant ans <= i;
        loop invariant min_bound <= p[0];
        loop invariant \forall integer k; 0 <= k < i ==> 1 <= p[k] <= n;
        loop invariant \forall integer k, l; 0 <= k < l < i ==> p[k] != p[l];
        loop invariant \forall integer k; 0 <= k < i ==> (min_bound <= p[k] || p[k] <= min_bound);
        loop invariant ((n) >= 3 && (n) <= 200000 &&
        \valid((p) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
        loop assigns i, ans, min_bound;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (min_bound >= p[i]) {
            ans += 1;
        }
        min_bound = (min_bound < p[i]) ? min_bound : p[i];
        i += 1;
    }
    //@ assert ans <= n;
    return ans;
}

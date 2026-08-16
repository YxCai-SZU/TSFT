#include <stddef.h>
#include <stdint.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((p) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int64_t func(size_t n, const int64_t *p) {
    int64_t ans = 0;
    size_t i = 1;

    /*@
        loop invariant 1 <= i <= n;
        loop invariant 0 <= ans <= i;
        loop invariant ((n) >= 1 && (n) <= 200000 &&
        \valid((p) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
        loop invariant i > 1 ==> ans <= i;
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i-1 < n;
        if (p[i - 1] <= (int64_t)(i + 1)) {
            ans += 1;
        }
        i += 1;
    }

    //@ assert ans <= n;
    return ans;
}

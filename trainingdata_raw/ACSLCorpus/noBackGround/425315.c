#include <stdint.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 100 &&
    (x) >= 1 && (x) <= 10000 &&
    \valid((a) + (0 .. (n)-1)) &&
    \forall integer j; 0 <= j < (n) ==> (a)[j] >= 1 && (a)[j] <= 10000);
    ensures \result >= 0;
    ensures \result <= n + 1;
    assigns \nothing;
*/
uint64_t func(size_t n, uint64_t x, uint64_t *a) {
    uint64_t result = 0;
    size_t i = 0;
    uint64_t sum = 0;

    /*@
        loop invariant (0 <= (i) && (i) <= (n) &&
    (sum) <= (x) &&
    (result) == (uint64_t)(i) &&
    \forall integer k; 0 <= k < (i) ==> (sum) >= (a)[k]);
        loop assigns i, sum, result;
        loop variant n - i;
    */
    while (i < n && sum + a[i] <= x) {
        //@ assert a[i] >= 1 && a[i] <= 10000;
        sum += a[i];
        result += 1;
        i += 1;
    }
    return result;
}

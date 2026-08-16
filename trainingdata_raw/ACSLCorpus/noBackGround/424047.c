#include <stdint.h>
#include <stdbool.h>

/*@
    requires n >= 2 && n <= 200000;
    requires \valid(a+(0..n-1));
    requires \forall integer i; 0 <= i < n ==> a[i] <= 1000000000;
    ensures \result >= 0 || \result == -1;
    assigns \nothing;
*/
int64_t func(uint64_t n, uint64_t *a) {
    uint64_t prev = UINT64_MAX;
    uint64_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant n >= 2 && n <= 200000;
        loop invariant \valid(a+(0..n-1));
        loop invariant \forall integer j; 0 <= j < n ==> a[j] <= 1000000000;
        loop invariant ((prev) == UINT64_MAX || (\exists integer k; 0 <= k < (i) && (prev) == (a)[k]));
        loop assigns i, prev;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert ((prev) == UINT64_MAX || (\exists integer k; 0 <= k < (i) && (prev) == (a)[k]));
        if (prev <= a[i]) {
            return -1;
        }
        prev = a[i];
        i = i + 1;
    }
    return 0;
}

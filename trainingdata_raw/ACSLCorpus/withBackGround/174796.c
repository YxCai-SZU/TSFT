#include <stddef.h>

/*@
    predicate equal_ranges{L}(int *a, int *b, integer n) =
        \forall integer i; 0 <= i < n ==> a[i] == b[i];
 */

/*@
    lemma seq_equal:
        \forall int *a, *b, integer n;
            equal_ranges(a, b, n) ==> \forall integer i; 0 <= i < n ==> a[i] == b[i];
 */

/*@
    requires n >= 0;
    requires \valid_read(a + (0 .. n-1));
    requires \valid_read(b + (0 .. n-1));
    requires equal_ranges(a, b, n);
    ensures \forall integer i; 0 <= i < n ==> a[i] == b[i];
 */
void example(int *a, int *b, size_t n) {
    /*@
        loop invariant 0 <= i <= n;
        loop invariant equal_ranges(a, b, i);
        loop assigns i;
        loop variant n - i;
     */
    for (size_t i = 0; i < n; ++i) {
        //@ assert a[i] == b[i];
    }
}

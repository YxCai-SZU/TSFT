#include <stdbool.h>
#include <stddef.h>

/*@ requires n > 0;
    requires \valid(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> a[i] > 0;
    assigns \nothing;
    ensures \result == true <==> (\forall integer i; 0 <= i < n ==> a[i] % 2 == 0);
 */
bool func(size_t n, size_t a[]) {
    bool all_even = true;
    size_t i = 0;

    /*@ loop invariant 0 <= i <= n;
        loop invariant all_even == true <==> (\forall integer j; 0 <= j < (i) ==> ((a)[j] % 2 == 0));
        loop invariant \forall integer k; 0 <= k < n ==> a[k] > 0;
        loop assigns i, all_even;
        loop variant n - i;
     */
    while (i < n) {
        //@ assert \forall integer k; 0 <= k < n ==> a[k] > 0;
        if (a[i] % 2 != 0) {
            all_even = false;
        }
        i++;
    }
    return all_even;
}

#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *a, size_t n) =
      n >= 2 && n <= 100000 &&
      \forall size_t i; 0 <= i < n ==> 1 <= a[i] && a[i] <= n;
*/

/*@ predicate option_none(ssize_t p) = p == -1;
    predicate option_some(ssize_t p, size_t idx) = p == (ssize_t)idx && idx < 100000;
*/

/*@ requires valid_array(a, n);
    assigns \nothing;
    ensures \result >= -1 && \result < (ssize_t)n;
    ensures \result >= 0 ==> a[\result] == (int)(\result + 1);
    ensures \result == -1 ==> \forall size_t i; i < n ==> a[i] != i+1;
*/
ssize_t func(size_t n, int *a) {
    ssize_t p = -1;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant valid_array(a, n);
        loop invariant p == -1 || (p >= 0 && (size_t)p < n);
        loop invariant p == -1 ==> \forall size_t j; 0 <= j < i ==> a[j] != j+1;
        loop invariant p >= 0 ==> a[(size_t)p] == (size_t)p + 1;
        loop assigns i, p;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (a[i] == (int)(i + 1)) {
            p = (ssize_t)i;
        }
        i++;
    }
    
    return p;
}

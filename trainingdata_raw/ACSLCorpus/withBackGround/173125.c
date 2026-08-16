#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_array(int *a, size_t n) =
      n >= 2 && n <= 100000 &&
      \forall size_t i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 10000;
*/

/*@ logic integer max_sum(integer n) = n * 10000; */

/*@ lemma sum_bound: \forall integer n; n >= 0 ==> max_sum(n) >= 0; */

/*@ requires \valid(a+(0..n-1));
    requires is_valid_array(a, n);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= max_sum(n);
*/
int func(size_t n, int *a) {
    int d = 0;
    size_t b = 0;
    
    /*@ loop invariant 0 <= b <= n;
        loop invariant d >= 0;
        loop invariant d <= max_sum(b);
        loop invariant is_valid_array(a, n);
        loop assigns d, b;
        loop variant n - b;
    */
    while (b < n) {
        if (b % 2 == 0) {
            int x = a[b];
            //@ assert x >= 1 && x <= 10000;
            d += x;
            //@ assert d >= 0;
            //@ assert d <= max_sum(b+1);
        }
        b += 1;
    }
    return d;
}

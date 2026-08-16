#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_array(integer n, int *p) =
        n >= 1 && n <= 200000 &&
        \valid(p + (0 .. n-1)) &&
        (\forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= n) &&
        (\forall integer i, j; 0 <= i < j < n ==> p[i] != p[j]);

    logic integer array_length{L}(int *p) = 200000;

    lemma array_bounds: \forall integer n, int *p; valid_array(n, p) ==> (\forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= n);
    lemma array_distinct: \forall integer n, int *p; valid_array(n, p) ==> (\forall integer i, j; 0 <= i < j < n ==> p[i] != p[j]);
*/

/*@
    requires valid_array(n, p);
    ensures \result >= 1 && \result <= n;
    assigns \nothing;
*/
size_t func(size_t n, const int *p) {
    size_t ret;
    size_t min_bound;
    size_t i;

    ret = 1;
    min_bound = (size_t)p[0];
    i = 1;

    /*@
        loop invariant i <= n;
        loop invariant ret >= 1 && ret <= i;
        loop invariant valid_array(n, p);
        loop invariant \forall integer k; 0 <= k < n ==> p[k] >= 1 && p[k] <= n;
        loop invariant \forall integer k, j; 0 <= k < j < n ==> p[k] != p[j];
        loop assigns i, ret, min_bound;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert valid_array(n, p);
        if (min_bound >= (size_t)p[i]) {
            ret = i + 1;
            min_bound = (size_t)p[i];
        }
        i += 1;
    }
    return ret;
}

int main() {
    return 0;
}

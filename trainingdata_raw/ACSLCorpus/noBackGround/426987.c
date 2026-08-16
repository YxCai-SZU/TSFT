#include <stddef.h>
#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (x) <= 10000 &&
        \valid((l) + (0 .. (n)-1)) &&
        \forall integer k; 0 <= k < (n) ==> 1 <= (l)[k] <= 100);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
size_t func(size_t n, size_t x, const size_t *l) {
    size_t d = 0;
    size_t count = 0;
    size_t i = 0;

    /*@
        loop invariant (0 <= (i) <= (n) &&
        0 <= (d) <= (x) + 100 &&
        0 <= (count) <= (i) &&
        \forall integer k; 0 <= k < (n) ==> 1 <= (l)[k] <= 100);
        loop assigns i, d, count;
        loop variant n - i;
    */
    while (i < n && d <= x) {
        //@ assert 0 <= count < i + 1;
        count = count + 1;
        //@ assert 1 <= l[i] <= 100;
        d = d + l[i];
        i = i + 1;
    }

    //@ assert 0 <= count <= n;
    return count;
}

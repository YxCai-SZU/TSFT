#include <stddef.h>
/*@
    predicate valid_array(integer n, size_t *ps) =
        3 <= n && n <= 20 &&
        \valid(ps + (0 .. n-1)) &&
        \forall integer k; 0 <= k < n ==> 1 <= ps[k] && ps[k] <= n &&
        \forall integer k, l; 0 <= k < l < n ==> ps[k] != ps[l];

    lemma count_bound: \forall integer n, integer i, integer count;
        3 <= n && n <= 20 &&
        2 <= i && i <= n &&
        count <= i - 2 ==>
        count <= n - 2;
*/


size_t func(size_t n, size_t *ps) {
    size_t count = 0;
    size_t i = 2;
    
    while (i < n) {
        //@ assert count <= n - 2;
        if (ps[i-1] < ps[i-2] && ps[i] < ps[i-1]) {
            count += 1;
        } else if (ps[i-1] < ps[i] && ps[i-2] < ps[i-1]) {
            count += 1;
        }
        i += 1;
    }
    //@ assert count <= n - 2;
    return count;
}

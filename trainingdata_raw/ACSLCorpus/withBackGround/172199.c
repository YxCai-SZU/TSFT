#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_array(integer n, int *a) =
        n >= 1 &&
        \valid(a + (0 .. n-1)) &&
        \forall integer j; 0 <= j < n ==> 1 <= a[j] <= 100;

    logic integer count_val(integer n, int *a, integer i) =
        i == 0 ? 1 : (a[i] <= a[i-1] ? 1 : 0);

    lemma count_bounds:
        \forall integer n, int *a, integer i;
        valid_array(n, a) && 0 <= i <= n ==>
        0 <= count_val(n, a, i) <= 1;
*/

/*@
    requires 1 <= n;
    requires \valid(a + (0 .. n-1));
    requires \forall integer j; 0 <= j < n ==> 1 <= a[j] <= 100;
    ensures \result >= 1;
    ensures \result <= n;
    assigns \nothing;
*/
size_t func(size_t n, int *a) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant i > 0 ==> count >= 1;
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        if (i == 0) {
            //@ assert count_val((integer)n, a, (integer)i) == 1;
            count += 1;
        } else {
            if (a[i] <= a[i - 1]) {
                //@ assert count_val((integer)n, a, (integer)i) == 1;
                count += 1;
            } else {
                //@ assert count_val((integer)n, a, (integer)i) == 0;
            }
        }
        i += 1;
    }
    return count;
}

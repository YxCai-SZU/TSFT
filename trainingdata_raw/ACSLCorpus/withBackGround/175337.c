#include <stdbool.h>

/*@
    predicate k_in_range(integer k) = 1 <= k <= 100000;
*/

/*@
    lemma calc_example_k:
        \forall integer k; k >= 1 && k <= 100000 ==> k_in_range(k);
*/

/*@
    requires 1 <= k <= 100000;
    ensures \result == k;
*/
int calc_example(int k) {
    //@ assert 1 <= k <= 100000;
    return k;
}

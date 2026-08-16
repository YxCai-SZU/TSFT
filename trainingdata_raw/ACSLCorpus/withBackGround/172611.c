#include <stdbool.h>
#include <stdint.h>

/*@
    predicate is_even(integer k) = k % 2 == 0;
    
    predicate map_equal(int *m1, int *m2) =
        \forall integer k; m1[k] == m2[k];
    
    predicate contains_key(int *m, integer k) =
        m[k] != 0;
*/

/*@
    requires map_equal(m1, m2);
    ensures \forall integer k; contains_key(m1, k) <==> contains_key(m2, k);
    ensures \forall integer k; contains_key(m1, k) ==> m1[k] == m2[k];
*/
void check_map_equality(int *m1, int *m2) {
    //@ assert map_equal(m1, m2);
}

/*@
    requires \forall integer k; contains_key(m, k) ==> is_even(k);
    ensures \forall integer k; contains_key(m, k) ==> is_even(k);
*/
void count_even_numbers(int *m) {
    //@ assert \forall integer k; contains_key(m, k) ==> is_even(k);
}

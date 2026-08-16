#include <stdbool.h>

/*@ predicate is_zero_at_index(long *a, integer idx) = a[idx] == 0; */

/*@ predicate vector_valid(long *a) = 
    \forall integer i; 0 <= i < 5 ==> 0 <= a[i] <= 1; */

/*@ predicate contains_zero(long *a) = 
    is_zero_at_index(a, 0) || 
    is_zero_at_index(a, 1) || 
    is_zero_at_index(a, 2) || 
    is_zero_at_index(a, 3) || 
    is_zero_at_index(a, 4); */

/*@ lemma zero_exists_in_range: 
    \forall long *a; vector_valid(a) && contains_zero(a) ==> 
    \exists integer k; 0 <= k < 5 && a[k] == 0; */

/*@ requires \valid(a + (0..4));
    requires contains_zero(a);
    requires vector_valid(a);
    ensures 1 <= \result <= 5;
    ensures is_zero_at_index(a, \result - 1);
    assigns \nothing;
 */
long func(long *a) {
    int i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant \forall integer k; 0 <= k < i ==> a[k] != 0;
        loop assigns i;
        loop variant 5 - i;
     */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (a[i] == 0) {
            //@ assert is_zero_at_index(a, i);
            return (long)(i + 1);
        }
        //@ assert a[i] != 0;
        i++;
    }
    return -1;
}

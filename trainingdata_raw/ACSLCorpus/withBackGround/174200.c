#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ predicate vector_len_eq_5(unsigned long long *xs) = 
      \valid(xs + (0 .. 4));
*/

/*@ predicate element_property(unsigned long long *xs, integer i) =
      xs[i] == i + 1 || xs[i] == 0;
*/

/*@ predicate exists_zero(unsigned long long *xs) =
      \exists integer j; 0 <= j < 5 && xs[j] == 0;
*/

/*@ predicate all_nonzero_prefix(unsigned long long *xs, integer i) =
      \forall integer k; 0 <= k < i ==> xs[k] != 0;
*/

/*@ lemma zero_exists_invariant:
      \forall unsigned long long *xs;
        vector_len_eq_5(xs) && exists_zero(xs) ==>
        \exists integer j; 0 <= j < 5 && xs[j] == 0;
*/

/*@ requires vector_len_eq_5(xs);
    requires \forall integer i; 0 <= i < 5 ==> element_property(xs, i);
    requires exists_zero(xs);
    ensures \result > 0 && \result < 6;
    ensures xs[\result - 1] == 0;
*/
uint64_t func(unsigned long long *xs) {
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant vector_len_eq_5(xs);
        loop invariant \forall integer j; 0 <= j < 5 ==> element_property(xs, j);
        loop invariant exists_zero(xs);
        loop invariant all_nonzero_prefix(xs, i);
        loop assigns i;
    */
    while (i < 5) {
        //@ assert i < 5;
        if (xs[i] == 0) {
            //@ assert xs[i] == 0;
            return (uint64_t)(i + 1);
        }
        //@ assert xs[i] != 0;
        i++;
    }
    return 0;
}

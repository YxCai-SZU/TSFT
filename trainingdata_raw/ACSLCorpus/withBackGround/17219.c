#include <stddef.h>
#include <stdbool.h>

/*@ predicate exists_zero(int* x, integer len) =
      \exists integer j; 0 <= j < len && x[j] == 0;
*/

/*@ predicate all_in_range(int* x, integer len) =
      \forall integer k; 0 <= k < len ==> 1 <= x[k] && x[k] <= 5;
*/

/*@ predicate all_nonzero_up_to(int* x, integer i) =
      \forall integer k; 0 <= k < i ==> x[k] != 0;
*/

/*@ lemma zero_exists_invariant:
      \forall int* x, integer len, integer i;
        all_in_range(x, len) && exists_zero(x, len) && 0 <= i <= len ==>
        exists_zero(x, len);
*/

/*@ lemma range_preserved:
      \forall int* x, integer len, integer i;
        all_in_range(x, len) && 0 <= i <= len ==> all_in_range(x, len);
*/

/*@ lemma nonzero_prefix:
      \forall int* x, integer i;
        all_nonzero_up_to(x, i) && i > 0 ==> all_nonzero_up_to(x, i);
*/

/*@ requires \valid(x+(0..4));
    requires all_in_range(x, 5);
    requires exists_zero(x, 5);
    ensures \result > 0 && \result <= 5;
    ensures x[\result - 1] == 0;
    assigns \nothing;
*/
size_t func(int* x) {
    size_t i = 0;
    /*@ loop invariant 0 <= i <= 5;
        loop invariant exists_zero(x, 5);
        loop invariant all_in_range(x, 5);
        loop invariant all_nonzero_up_to(x, i);
        loop invariant i > 0 ==> all_nonzero_up_to(x, i);
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        if (x[i] == 0) {
            //@ assert 0 <= i + 1 <= 5;
            return i + 1;
        }
        i++;
    }
    return 0;
}

int main() {
    return 0;
}

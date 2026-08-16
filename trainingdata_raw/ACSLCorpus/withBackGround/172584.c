#include <stdbool.h>
#include <stddef.h>

/*@ predicate exists_zero_at(long long *a, integer i) =
      (0 <= i < 5) && (a[i] == 0);
*/

/*@ predicate exists_zero(long long *a) =
      \exists integer i; exists_zero_at(a, i);
*/

/*@ predicate all_nonzero_upto(long long *a, integer idx) =
      \forall integer j; (0 <= j < idx) ==> (a[j] != 0);
*/

/*@ lemma loop_invariant_maintained:
      \forall long long *a, integer idx;
        (0 <= idx <= 5) && exists_zero(a) && all_nonzero_upto(a, idx) && idx < 5 ==>
        (a[idx] == 0 ==> exists_zero_at(a, idx)) &&
        (a[idx] != 0 ==> (0 <= idx+1 <= 5) && all_nonzero_upto(a, idx+1) && exists_zero(a));
*/

/*@
    requires \valid(a + (0 .. 4));
    requires exists_zero(a);
    ensures 1 <= \result <= 5;
    ensures exists_zero_at(a, \result - 1);
    assigns \nothing;
*/
int func(const long long *a) {
    size_t index = 0;
    /*@
        loop invariant 0 <= index <= 5;
        loop invariant exists_zero(a);
        loop invariant all_nonzero_upto(a, index);
        loop assigns index;
        loop variant 5 - index;
    */
    while (index < 5) {
        long long e = a[index];
        if (e == 0) {
            //@ assert exists_zero_at(a, index);
            return (int)(index + 1);
        }
        //@ assert a[index] != 0;
        index++;
    }
    return -1;
}

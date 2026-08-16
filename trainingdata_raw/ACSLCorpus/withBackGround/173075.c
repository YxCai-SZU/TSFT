#include <stdbool.h>

/*@ predicate vector_len_5(long long *v) =
      \valid(v + (0 .. 4));
*/

/*@ predicate has_zero(long long *v) =
      v[0] == 0 || v[1] == 0 || v[2] == 0 || v[3] == 0 || v[4] == 0;
*/

/*@ predicate all_nonzero_before(long long *v, integer i) =
      \forall integer j; 0 <= j < i ==> v[j] != 0;
*/

/*@ lemma precondition_implies_zero_exists:
      \forall long long *v;
        vector_len_5(v) && has_zero(v) ==>
        \exists integer k; 0 <= k < 5 && v[k] == 0;
*/

/*@ requires \valid(v + (0 .. 4));
    requires v[0] == 0 || v[1] == 0 || v[2] == 0 || v[3] == 0 || v[4] == 0;
    ensures 1 <= \result <= 5;
    ensures v[\result - 1] == 0;
*/
long long func(long long *v) {
    int i = 0;
    /*@ loop invariant 0 <= i <= 5;
        loop invariant \valid(v + (0 .. 4));
        loop invariant v[0] == 0 || v[1] == 0 || v[2] == 0 || v[3] == 0 || v[4] == 0;
        loop invariant \forall integer j; 0 <= j < i ==> v[j] != 0;
        loop assigns i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (v[i] == 0) {
            //@ assert v[i] == 0;
            return (long long)(i + 1);
        }
        //@ assert v[i] != 0;
        i++;
    }
    //@ assert i == 5;
    //@ assert \forall integer j; 0 <= j < 5 ==> v[j] != 0;
    //@ assert false;
    return -1;
}

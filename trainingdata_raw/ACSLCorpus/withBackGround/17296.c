#include <stddef.h>

/*@ predicate vector_len_eq_7(int *v) =
      \valid(v + (0 .. 6));
*/

/*@ predicate vector_vals(int *v) =
      v[0] == 0 &&
      v[1] == 1 &&
      v[2] == 2 &&
      v[3] == 3 &&
      v[4] == 4 &&
      v[5] == 5 &&
      v[6] == 6;
*/

/*@ lemma loop_invariant_maintained:
      \forall int *v, size_t i, size_t ans;
      vector_len_eq_7(v) && vector_vals(v) &&
      0 <= i <= 6 && ans <= 6 ==>
      (i < 6 ==> ans <= 6);
*/

/*@ requires \valid(v + (0 .. 6));
    requires v[0] == 0 && v[1] == 1 && v[2] == 2 &&
             v[3] == 3 && v[4] == 4 && v[5] == 5 &&
             v[6] == 6;
    ensures \result <= 6;
    assigns \nothing;
*/
size_t func(int *v) {
    size_t ans;
    size_t i;
    ans = 0;
    i = 0;

    /*@ loop invariant 0 <= i <= 6;
        loop invariant vector_len_eq_7(v);
        loop invariant vector_vals(v);
        loop invariant ans <= 6;
        loop assigns i, ans;
        loop variant 6 - i;
    */
    while (i < 6) {
        //@ assert vector_len_eq_7(v);
        if (v[i] < v[i + 1]) {
            ans = i + 1;
        }
        i += 1;
    }
    return ans;
}

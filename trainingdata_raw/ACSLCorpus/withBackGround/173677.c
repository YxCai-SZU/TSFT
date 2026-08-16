#include <stdbool.h>

/*@ predicate vec_len_eq_two(int *v) = \valid(v) && \valid(v+1);
    predicate v0_in_range(int *v) = 1 <= v[0] <= 100;
    predicate v1_in_range(int *v) = 0 <= v[1] <= v[0];
    predicate v0_eq_v1(int *v) = v[0] == v[1];
 */

/*@ requires vec_len_eq_two(v);
    requires v0_in_range(v);
    requires v1_in_range(v);
    ensures \result == (v[0] == v[1]);
    assigns \nothing;
 */
bool func(int *v) {
    int i;
    
    //@ assert vec_len_eq_two(v);
    //@ assert v0_in_range(v);
    //@ assert v1_in_range(v);
    
    if (v[0] == v[1]) {
        //@ assert v0_eq_v1(v);
        return true;
    } else {
        i = 0;
        /*@ loop invariant 0 <= i <= 2;
            loop invariant vec_len_eq_two(v);
            loop invariant v0_in_range(v);
            loop invariant v1_in_range(v);
            loop invariant v[0] != v[1];
            loop assigns i;
            loop variant 2 - i;
         */
        while (i < 2) {
            //@ assert v[0] != v[1];
            i = i + 1;
        }
        //@ assert v[0] != v[1];
        return false;
    }
}

#include <stdbool.h>

/*@
    predicate valid_vector(int *v, integer len) =
        len == 6 &&
        \forall integer i; 0 <= i < len ==> 0 <= v[i] <= 123 &&
        v[0] < v[1] < v[2] < v[3] < v[4];
*/

/*@
    logic integer diff(int *v) = v[4] - v[0];
*/

/*@
    lemma diff_nonnegative:
        \forall int *v; valid_vector(v, 6) ==> diff(v) >= 0;
*/

/*@
    requires \valid(v + (0..5));
    requires valid_vector(v, 6);
    ensures \result == (diff(v) <= v[5]);
*/
bool func(int *v) {
    //@ assert v[0] < v[1] < v[2] < v[3] < v[4];
    
    if (v[0] < v[1] && v[1] < v[2] && v[2] < v[3] && v[3] < v[4]) {
        //@ assert diff(v) >= 0;
        return v[4] - v[0] <= v[5];
    } else {
        return false;
    }
}

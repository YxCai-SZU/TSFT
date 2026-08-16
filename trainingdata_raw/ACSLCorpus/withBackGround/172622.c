#include <stdbool.h>

/*@ predicate is_valid_vector(int *v, integer len) =
    len == 2 &&
    \valid(v + (0 .. 1)) &&
    0 <= v[0] && v[0] <= 16 &&
    0 <= v[1] && v[1] <= 16 &&
    v[0] + v[1] <= 16;
*/

/*@ logic integer vector_max(integer a, integer b) =
    a > b ? a : b;
*/

/*@ lemma max_is_either:
    \forall integer a, integer b;
    vector_max(a, b) == a || vector_max(a, b) == b;
*/

/*@
    requires is_valid_vector(v, 2);
    assigns \nothing;
    ensures \result == (v[0] <= 8 || v[1] <= 8);
*/
bool func(int *v) {
    int max_val;
    
    //@ assert v[0] >= 0 && v[0] <= 16;
    //@ assert v[1] >= 0 && v[1] <= 16;
    //@ assert v[0] + v[1] <= 16;
    
    if (v[0] > v[1]) {
        max_val = v[0];
    } else {
        max_val = v[1];
    }
    
    //@ assert max_val == v[0] || max_val == v[1];
    
    return v[0] <= 8 || v[1] <= 8;
}

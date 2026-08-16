#include <stdbool.h>

/*@ predicate valid_vec(int *v) =
      \valid(v) && \valid(v+1) && \valid(v+2) &&
      1 <= v[0] <= 9 &&
      1 <= v[1] <= 9 &&
      1 <= v[2] <= 9;
*/

/*@ lemma subtraction_bounds:
      \forall int *v; valid_vec(v) ==>
        -8 <= v[1] - v[0] <= 8 &&
        -8 <= v[2] - v[1] <= 8;
*/

/*@ requires valid_vec(v);
    ensures \result == (v[1] - v[0] == v[2] - v[1]);
    assigns \nothing;
*/
bool func(int *v) {
    // Variable declarations at scope top
    bool result;
    
    //@ assert 1 <= v[1] <= 9;
    //@ assert 1 <= v[0] <= 9;
    //@ assert 1 <= v[2] <= 9;
    
    //@ assert v[1] - v[0] >= -8 && v[1] - v[0] <= 8;
    //@ assert v[2] - v[1] >= -8 && v[2] - v[1] <= 8;
    
    result = (v[1] - v[0] == v[2] - v[1]);
    return result;
}

#include <stdbool.h>

/*@ predicate valid_vector(int *v, integer len) =
    len == 3 &&
    \forall integer i; 0 <= i < len ==> 1 <= v[i] <= 13;
*/

/*@ logic integer vector_at(int *v, integer i) = v[i]; */

/*@ lemma triangle_inequality:
    \forall int *v; \forall integer len;
    valid_vector(v, len) ==>
    (vector_at(v, 1) + vector_at(v, 2) >= vector_at(v, 0) &&
     vector_at(v, 0) + vector_at(v, 2) >= vector_at(v, 1) &&
     vector_at(v, 0) + vector_at(v, 1) >= vector_at(v, 2)) ==
    !(vector_at(v, 1) + vector_at(v, 2) < vector_at(v, 0) ||
      vector_at(v, 0) + vector_at(v, 2) < vector_at(v, 1) ||
      vector_at(v, 0) + vector_at(v, 1) < vector_at(v, 2));
*/

/*@
    requires \valid(v + (0..2));
    requires valid_vector(v, 3);
    ensures \result == (v[1] + v[2] >= v[0] && v[0] + v[2] >= v[1] && v[0] + v[1] >= v[2]);
    assigns \nothing;
*/
bool func(int *v) {
    bool result;
    //@ assert valid_vector(v, 3);
    
    result = v[1] + v[2] >= v[0] && v[0] + v[2] >= v[1] && v[0] + v[1] >= v[2];
    
    if (v[1] + v[2] < v[0] || v[0] + v[2] < v[1] || v[0] + v[1] < v[2]) {
        result = false;
    }
    
    //@ assert result == (v[1] + v[2] >= v[0] && v[0] + v[2] >= v[1] && v[0] + v[1] >= v[2]);
    
    return result;
}

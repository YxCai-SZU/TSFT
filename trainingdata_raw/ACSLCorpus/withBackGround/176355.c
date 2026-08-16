#include <stdbool.h>

/*@
    predicate valid_vector(int *v, integer len) =
        len >= 3 &&
        1 <= v[0] <= 13 &&
        1 <= v[1] <= 13 &&
        1 <= v[2] <= 13;

    predicate is_max(int *v, integer len) =
        v[2] >= v[0] && v[2] >= v[1];

    lemma bounds_lemma:
        \forall int *v, integer len;
        valid_vector(v, len) ==>
        0 < len && 1 < len && 2 < len;
*/

/*@
    requires \valid(v + (0 .. 2));
    requires valid_vector(v, len);
    ensures \result == true <==> is_max(v, len);
    assigns \nothing;
*/
bool func(int *v, int len) {
    // Variable declarations at top of scope
    bool result;

    //@ assert len >= 3;
    //@ assert 0 < len;
    //@ assert 1 < len;
    //@ assert 2 < len;

    if (v[2] >= v[0] && v[2] >= v[1]) {
        result = true;
    } else {
        result = false;
    }

    return result;
}

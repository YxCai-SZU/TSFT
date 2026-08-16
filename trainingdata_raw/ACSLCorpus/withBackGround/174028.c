#include <stdbool.h>

/*@
    predicate valid_vector(int *v, integer len) =
        len == 6 &&
        \forall integer i; 0 <= i < len ==> 1 <= v[i] <= 123 &&
        v[4] - v[0] <= v[5];

    logic integer vector_len(int *v) = 6;

    lemma vector_property:
        \forall int *v; valid_vector(v, vector_len(v)) ==> v[4] - v[0] <= v[5];
*/

/*@
    requires \valid(v + (0..5));
    requires valid_vector(v, 6);
    ensures \result == true <==> v[4] - v[0] <= v[5];
    assigns \nothing;
*/
bool func(int *v) {
    int v0;
    int v4;
    int v5;
    bool result;

    v0 = v[0];
    v4 = v[4];
    v5 = v[5];

    //@ assert v[4] - v[0] <= v[5];
    result = (v4 - v0) <= v5;
    return result;
}

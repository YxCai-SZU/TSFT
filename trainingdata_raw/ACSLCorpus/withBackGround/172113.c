#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_vector(int *v, size_t len) =
        len >= 3 &&
        1 <= v[0] <= 9 &&
        1 <= v[1] <= 9 &&
        1 <= v[2] <= 9;

    logic integer compute_value(integer v0, integer v1, integer v2) =
        (v1 * 100) + (v2 * 10) + v0;

    lemma compute_value_bounds:
        \forall integer v0, v1, v2;
        1 <= v0 <= 9 && 1 <= v1 <= 9 && 1 <= v2 <= 9 ==>
        111 <= compute_value(v0, v1, v2) <= 999;
*/

/*@
    requires \valid_read(v + (0 .. 2));
    requires valid_vector(v, len);
    ensures \result == (compute_value(v[0], v[1], v[2]) % 4 == 0);
*/
bool func(int *v, size_t len) {
    int v0;
    int v1;
    int v2;
    int computed;
    bool result;

    //@ assert len >= 3;
    v0 = v[0];
    v1 = v[1];
    v2 = v[2];
    
    //@ assert 1 <= v0 <= 9;
    //@ assert 1 <= v1 <= 9;
    //@ assert 1 <= v2 <= 9;
    
    computed = (v1 * 100) + (v2 * 10) + v0;
    
    //@ assert computed == compute_value(v0, v1, v2);
    //@ assert 111 <= computed <= 999;
    
    if (computed % 4 == 0) {
        //@ assert computed % 4 == 0;
        result = true;
    } else {
        //@ assert computed % 4 != 0;
        result = false;
    }
    
    //@ assert result == (compute_value(v0, v1, v2) % 4 == 0);
    return result;
}

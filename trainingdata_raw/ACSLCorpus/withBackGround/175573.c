#include <stdbool.h>

/*@
    predicate valid_vec(int *v, integer len) =
        len == 2 &&
        1 <= v[0] && v[0] <= 100 &&
        1 <= v[1] && v[1] <= 100;

    predicate result_condition(integer a, integer b) =
        a == 1 || b == 1;
*/

/*@
    requires \valid(v + (0..1));
    requires valid_vec(v, 2);
    assigns \nothing;
    ensures \result == 1 <==> result_condition(v[0], v[1]);
*/
bool func(int *v) {
    //@ assert v[0] >= 1 && v[0] <= 100;
    //@ assert v[1] >= 1 && v[1] <= 100;
    
    if (v[0] == 1 || v[1] == 1) {
        return true;
    } else {
        return false;
    }
}

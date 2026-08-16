#include <stdbool.h>

/*@ predicate valid_vector(int *v, integer len) =
    len >= 3 &&
    1 <= v[0] <= 100 &&
    1 <= v[1] <= 100 &&
    1 <= v[2] <= 200;
*/

/*@ predicate condition_holds(int *v) =
    v[0] <= v[2] && v[2] <= v[0] + v[1];
*/

/*@
    requires \valid(v+(0..2));
    requires valid_vector(v, 3);
    ensures \result == true <==> condition_holds(v);
*/
bool func(int *v) {
    // Variable declarations at top of scope
    bool result;

    //@ assert valid_vector(v, 3);
    
    if (v[0] <= v[2] && v[2] <= v[0] + v[1]) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}

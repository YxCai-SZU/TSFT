#include <stdbool.h>

/*@ predicate valid_vector(int *v, integer len) =
    len == 2 &&
    1 <= v[0] && v[0] <= 100 &&
    0 <= v[1] && v[1] <= 4111;
*/

/*@ logic integer compute_condition(integer x, integer y) =
    (y >= x * 2 - 1) ? 1 : 0;
*/

/*@
    requires \valid(v + (0..1));
    requires valid_vector(v, 2);
    ensures \result == (compute_condition(v[0], v[1]) == 1);
*/
bool func(int *v) {
    bool result = false;
    int x = 0;
    int y = 0;
    
    x = v[0];
    y = v[1];
    
    //@ assert x >= 1 && x <= 100;
    
    if (y >= x * 2 - 1) {
        result = true;
    }
    
    //@ assert result == (y >= x * 2 - 1);
    return result;
}

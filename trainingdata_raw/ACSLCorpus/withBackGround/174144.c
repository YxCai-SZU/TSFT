#include <stdbool.h>

/*@
    predicate valid_vec(int *v, integer len) =
        len == 3 &&
        v[0] >= -100 &&
        v[1] <= 100 &&
        v[2] >= -100 && v[2] <= 100;

    predicate is_max_middle(integer a, integer b, integer c) =
        b >= a && b >= c;
*/

/*@
    requires \valid(v + (0..2));
    requires valid_vec(v, 3);
    ensures \result == 1 <==> is_max_middle(v[0], v[1], v[2]);
    assigns \nothing;
*/
bool func(int *v)
{
    bool result;
    //@ assert v[0] >= -100;
    //@ assert v[1] <= 100;
    //@ assert v[2] >= -100 && v[2] <= 100;
    
    result = (v[1] >= v[0] && v[1] >= v[2]);
    return result;
}

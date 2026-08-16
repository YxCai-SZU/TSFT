#include <stdbool.h>

/*@
    predicate valid_vector(int *v, integer len) =
        len == 3 &&
        v[0] >= 0 && v[1] >= 0 && v[2] >= 0;

    predicate is_strictly_increasing(int *v) =
        v[0] < v[1] && v[1] < v[2];
*/

/*@
    requires \valid(v + (0..2));
    requires valid_vector(v, 3);
    ensures \result == 1 <==> is_strictly_increasing(v);
*/
bool func(int *v)
{
    //@ assert valid_vector(v, 3);
    return v[0] < v[1] && v[1] < v[2];
}

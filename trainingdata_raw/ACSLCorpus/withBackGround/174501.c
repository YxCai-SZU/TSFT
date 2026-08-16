#include <stdbool.h>

/*@
    predicate valid_vector(int *v, integer len) =
        len == 6 &&
        0 <= v[0] <= 123 &&
        0 <= v[1] <= 123 &&
        0 <= v[2] <= 123 &&
        0 <= v[3] <= 123 &&
        0 <= v[4] <= 123 &&
        0 <= v[5] <= 123;

    predicate condition(int *v) =
        v[4] - v[0] <= v[5] &&
        v[0] <= v[4] &&
        v[4] <= v[0] + v[5];
*/

/*@
    requires \valid(v+(0..5));
    requires valid_vector(v, 6);
    ensures \result == 1 <==> condition(v);
*/
bool func(int *v)
{
    //@ assert v[4] - v[0] <= v[5] && v[0] <= v[4] && v[4] <= v[0] + v[5] ==> condition(v);
    if (v[4] - v[0] <= v[5] && v[0] <= v[4] && v[4] <= v[0] + v[5]) {
        //@ assert condition(v);
        return true;
    } else {
        //@ assert !condition(v);
        return false;
    }
}

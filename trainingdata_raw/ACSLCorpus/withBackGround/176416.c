#include <stdbool.h>

/*@
    predicate valid_vector(int *v, integer len) =
        len == 3 &&
        \forall integer i; 0 <= i < len ==> 1 <= v[i] <= 13;

    predicate condition(int *v) =
        v[1] < v[2] && v[2] < v[0] ||
        v[1] < v[2] && v[2] >= v[0];
*/

/*@
    requires valid_vector(v, 3);
    ensures \result == 1 <==> condition(v);
    assigns \nothing;
*/
bool func(int *v)
{
    bool result;

    //@ assert 0 < 3;
    //@ assert 1 < 3;
    //@ assert 2 < 3;

    if (v[1] < v[2] && v[2] < v[0] || v[1] < v[2] && v[2] >= v[0])
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == 1 <==> condition(v);
    return result;
}

#include <stdbool.h>

/*@
    predicate is_increasing(int *arr, integer len) =
        len >= 3 ==> arr[0] < arr[1] && arr[1] < arr[2];
*/

/*@
    requires \valid_read(v + (0 .. 2));
    requires len >= 3;
    assigns \nothing;
    ensures \result == (v[0] < v[1] && v[1] < v[2]);
*/
bool func(int *v, int len)
{
    int n;
    bool result;

    n = len;
    //@ assert n >= 3;
    //@ assert len >= 3;
    result = v[0] < v[1] && v[1] < v[2];
    return result;
}

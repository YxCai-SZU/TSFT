#include <stdbool.h>

/*@
    predicate is_valid_range(int *arr, integer len) =
        len == 3 &&
        arr[0] >= 0 && arr[0] <= 100 &&
        arr[1] >= 0 && arr[1] <= 100 &&
        arr[2] >= 0 && arr[2] <= 100;

    predicate is_strictly_increasing(int *arr) =
        arr[0] < arr[1] && arr[1] < arr[2];
*/

/*@
    requires \valid_read(v + (0 .. 2));
    requires is_valid_range(v, 3);
    ensures \result == 1 <==> is_strictly_increasing(v);
*/
bool func(int v[3])
{
    bool result;
    //@ assert v[0] >= 0 && v[0] <= 100;
    //@ assert v[1] >= 0 && v[1] <= 100;
    //@ assert v[2] >= 0 && v[2] <= 100;

    if (v[0] < v[1] && v[1] < v[2]) {
        //@ assert v[0] < v[1] && v[1] < v[2];
        result = true;
    } else {
        result = false;
    }
    return result;
}

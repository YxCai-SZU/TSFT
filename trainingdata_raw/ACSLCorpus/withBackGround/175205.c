#include <stdbool.h>

/*@
    predicate valid_vec(int *arr, integer len) =
        len == 3 &&
        \valid(arr + (0 .. 2)) &&
        arr[0] >= 1 && arr[0] <= 100 &&
        arr[1] >= 1 && arr[1] <= 100 &&
        arr[2] >= 1 && arr[2] <= 100;

    predicate is_arithmetic(int *arr) =
        arr[1] - arr[0] == arr[2] - arr[1];
*/

/*@
    requires valid_vec(s, 3);
    ensures \result == 1 <==> is_arithmetic(s);
    assigns \nothing;
*/
bool func(int *s)
{
    //@ assert s[0] >= 1 && s[0] <= 100;
    return s[1] - s[0] == s[2] - s[1];
}

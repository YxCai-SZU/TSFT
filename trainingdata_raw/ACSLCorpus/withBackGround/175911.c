#include <stdbool.h>

/*@
    predicate is_valid_range(int *arr, integer len) =
        len == 2 &&
        arr[0] >= 0 && arr[0] <= 100 &&
        arr[1] >= 0 && arr[1] <= 100;

    predicate both_are_one(int *arr) =
        arr[0] == 1 && arr[1] == 1;
*/

/*@
    requires \valid(a + (0..1));
    requires is_valid_range(a, 2);
    ensures \result <==> both_are_one(a);
    assigns \nothing;
*/
bool func(int *a)
{
    bool result;
    
    //@ assert is_valid_range(a, 2);
    result = (a[0] == 1 && a[1] == 1);
    return result;
}

#include <stdbool.h>
/*@
    predicate valid_range(int *arr, integer len) =
        len >= 3 &&
        \forall integer i; 0 <= i < len ==> 1 <= arr[i] && arr[i] <= 100;

    predicate result_condition(int *arr) =
        arr[1] < arr[2] && arr[2] < arr[0];
*/

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires valid_range(arr, len);
    ensures \result == 1 <==> result_condition(arr);
*/
bool func(int *arr, int len) {
    bool result;

    //@ assert len >= 3;
    result = arr[1] < arr[2] && arr[2] < arr[0];
    //@ assert result == 1 <==> result_condition(arr);
    return result;
}

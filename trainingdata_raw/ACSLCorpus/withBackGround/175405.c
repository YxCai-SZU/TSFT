#include <stdbool.h>

/*@
    predicate valid_range(int *arr, integer len) =
        len == 6 &&
        \forall integer i; 0 <= i < len ==> 1 <= arr[i] && arr[i] <= 100;

    predicate result_condition(int *arr) =
        arr[4] >= arr[0] && arr[5] >= arr[1] && arr[2] >= arr[0] && arr[3] >= arr[1];
*/

/*@
    requires \valid(arr + (0 .. 5));
    requires valid_range(arr, 6);
    ensures \result == \true <==> result_condition(arr);
*/
bool func(int *arr) {
    bool result;

    //@ assert valid_range(arr, 6);
    //@ assert \forall integer i; 0 <= i < 6 ==> 1 <= arr[i] && arr[i] <= 100;

    result = (arr[4] >= arr[0]) && (arr[5] >= arr[1]) && 
             (arr[2] >= arr[0]) && (arr[3] >= arr[1]);

    //@ assert result == \true <==> result_condition(arr);
    return result;
}

#include <stdbool.h>

/*@ predicate valid_input(int *arr, integer len) =
    len == 2 &&
    \forall integer i; 0 <= i < len ==> arr[i] <= 100 &&
    arr[0] >= 1 && arr[1] >= 1;
*/

/*@ predicate result_condition(int *arr, bool res) =
    res == (arr[0] <= arr[1]);
*/

/*@
    requires \valid_read(arr + (0 .. 1));
    requires valid_input(arr, 2);
    ensures result_condition(arr, \result);
    assigns \nothing;
*/
bool func(const int *arr) {
    int a;
    int b;
    bool res;

    //@ assert arr[0] >= 1;
    //@ assert arr[1] >= 1;
    //@ assert \forall integer i; 0 <= i < 2 ==> arr[i] <= 100;

    a = arr[0];
    b = arr[1];
    res = (a <= b);
    return res;
}

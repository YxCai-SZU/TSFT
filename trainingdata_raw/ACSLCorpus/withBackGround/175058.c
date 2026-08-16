#include <stdbool.h>

/*@
    predicate valid_range(int *arr, integer len) =
        len == 6 &&
        0 <= arr[0] <= 123 &&
        0 <= arr[1] <= 123 &&
        0 <= arr[2] <= 123 &&
        0 <= arr[3] <= 123 &&
        0 <= arr[4] <= 123 &&
        0 <= arr[5] <= 123;

    predicate result_condition(int *arr, bool res) =
        res == true <==> 
        (arr[0] < arr[2] && arr[2] < arr[4] && 
         arr[4] < arr[1] && arr[1] < arr[3] && arr[3] < arr[5]);
*/

/*@
    requires \valid_read(v + (0 .. 5));
    requires valid_range(v, 6);
    ensures result_condition(v, \result);
    assigns \nothing;
*/
bool func(int *v) {
    // Variable declarations at top of scope
    bool result;

    //@ assert 0 <= v[0] && v[0] <= 123;
    //@ assert 0 <= v[1] && v[1] <= 123;
    //@ assert 0 <= v[2] && v[2] <= 123;
    //@ assert 0 <= v[3] && v[3] <= 123;
    //@ assert 0 <= v[4] && v[4] <= 123;
    //@ assert 0 <= v[5] && v[5] <= 123;

    //@ assert 0 <= 0 && 0 < 6;
    //@ assert 0 <= 1 && 1 < 6;
    //@ assert 0 <= 2 && 2 < 6;
    //@ assert 0 <= 3 && 3 < 6;
    //@ assert 0 <= 4 && 4 < 6;
    //@ assert 0 <= 5 && 5 < 6;

    if (v[0] < v[2] && v[2] < v[4] && v[4] < v[1] && v[1] < v[3] && v[3] < v[5]) {
        result = true;
    } else {
        result = false;
    }

    return result;
}

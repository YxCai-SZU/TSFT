#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_increasing(int* arr, integer len) =
        len >= 3 ==> arr[0] < arr[1] && arr[1] < arr[2];
*/

/*@
    requires \valid_read(arr + (0 .. 2));
    requires len >= 3;
    assigns \nothing;
    ensures \result == (arr[0] < arr[1] && arr[1] < arr[2]);
*/
bool func(int* arr, size_t len) {
    bool result;
    //@ assert len >= 3;
    
    if (len < 3) {
        result = false;
    } else {
        result = (arr[0] < arr[1] && arr[1] < arr[2]);
    }
    
    return result;
}

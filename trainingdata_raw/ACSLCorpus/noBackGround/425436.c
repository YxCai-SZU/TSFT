#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires ((len) >= 3 &&
        \forall size_t i; 0 <= i < (len) ==> 1 <= (arr)[i] <= 1000);
    assigns \nothing;
    ensures \result == 1 <==> (((arr)[1] < (arr)[2] && (arr)[2] < (arr)[(len) - 1]) ||
        ((arr)[1] > (arr)[2] && (arr)[2] > (arr)[(len) - 1]));
*/
bool func(int *arr, size_t len) {
    bool result;
    //@ assert len >= 3;
    
    if (arr[1] < arr[2] && arr[2] < arr[len - 1]) {
        result = true;
        //@ assert (((arr)[1] < (arr)[2] && (arr)[2] < (arr)[(len) - 1]) ||         ((arr)[1] > (arr)[2] && (arr)[2] > (arr)[(len) - 1]));
    } else if (arr[1] > arr[2] && arr[2] > arr[len - 1]) {
        result = true;
        //@ assert (((arr)[1] < (arr)[2] && (arr)[2] < (arr)[(len) - 1]) ||         ((arr)[1] > (arr)[2] && (arr)[2] > (arr)[(len) - 1]));
    } else {
        result = false;
        //@ assert !(((arr)[1] < (arr)[2] && (arr)[2] < (arr)[(len) - 1]) ||         ((arr)[1] > (arr)[2] && (arr)[2] > (arr)[(len) - 1]));
    }
    
    return result;
}

#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. 2));
    requires ((len) == 3 &&
        (arr)[0] <= 100 &&
        (arr)[1] <= 100 &&
        (arr)[2] <= 200);
    ensures \result == (arr[2] <= arr[0] + arr[1]);
*/
bool func(unsigned long *arr, size_t len) {
    // Variable declarations at top of scope
    bool result;

    //@ assert len == 3;
    //@ assert arr[0] <= 100 && arr[1] <= 100 && arr[2] <= 200;

    result = (arr[2] <= arr[0] + arr[1]);
    return result;
}

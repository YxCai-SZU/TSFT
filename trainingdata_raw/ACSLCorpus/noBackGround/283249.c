#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. 2));
  requires ((len) >= 3 &&
      1 <= (arr)[0] && (arr)[0] <= 13 &&
      1 <= (arr)[1] && (arr)[1] <= 13 &&
      1 <= (arr)[2] && (arr)[2] <= 13);
  ensures \result == true <==> ((arr)[2] >= (arr)[0] && (arr)[2] >= (arr)[1]);
*/
bool func(int* arr, size_t len) {
    // Variable declarations at top
    bool result;

    //@ assert len >= 3;
    //@ assert 1 <= arr[0] && arr[0] <= 13;
    //@ assert 1 <= arr[1] && arr[1] <= 13;
    //@ assert 1 <= arr[2] && arr[2] <= 13;

    if (arr[2] >= arr[0] && arr[2] >= arr[1]) {
        result = true;
    } else {
        result = false;
    }

    return result;
}

#include <stdbool.h>

/*@ predicate is_non_decreasing(integer a, integer b, integer c) =
      a <= b && b <= c;
*/

/*@
  requires \valid_read(arr + (0..2));
  requires arr_len >= 3;
  ensures \result == (arr[0] <= arr[1] && arr[1] <= arr[2]);
*/
bool non_decreasing_subsequence(const int* arr, int arr_len) {
    int first;
    int second;
    int third;
    bool ret;

    //@ assert arr_len >= 3;
    first = arr[0];
    second = arr[1];
    third = arr[2];
    ret = (first <= second) && (second <= third);
    //@ assert ret == (arr[0] <= arr[1] && arr[1] <= arr[2]);
    return ret;
}

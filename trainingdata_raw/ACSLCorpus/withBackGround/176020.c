#include <stdbool.h>

/*@ predicate is_sorted_prefix(int *arr, integer len) =
      len >= 3 ==> arr[0] < arr[1] && arr[1] < arr[2];
*/

/*@
  requires \valid_read(v + (0 .. 2));
  requires len >= 3;
  ensures \result == (v[0] < v[1] && v[1] < v[2]);
*/
bool func(int *v, int len) {
    int a;
    int b;
    int c;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];
    result = false;

    if (a < b && b < c) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == (a < b && b < c);
    return result;
}

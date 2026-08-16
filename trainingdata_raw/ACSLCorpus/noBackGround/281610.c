#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. 2));
  requires ((len) >= 3 &&
      \forall integer i; 0 <= i < 3 ==> 1 <= (arr)[i] <= 9);
  assigns \nothing;
  ensures \result == (arr[0] < arr[1] && arr[1] < arr[2] ||
                      arr[0] > arr[1] && arr[1] > arr[2]);
*/
bool func(int *arr, size_t len) {
    int a;
    int b;
    int c;
    bool increasing;
    bool decreasing;
    int result;
    bool result_bool;

    //@ assert ((len) >= 3 &&       \forall integer i; 0 <= i < 3 ==> 1 <= (arr)[i] <= 9);
    a = arr[0];
    b = arr[1];
    c = arr[2];

    //@ assert 1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9;
    if (a < b) {
        increasing = (b < c);
    } else {
        increasing = false;
    }

    if (a > b) {
        decreasing = (b > c);
    } else {
        decreasing = false;
    }

    result = (increasing || decreasing) ? 1 : 0;
    result_bool = (result == 1);

    //@ assert result_bool == (a < b && b < c || a > b && b > c);
    return result_bool;
}

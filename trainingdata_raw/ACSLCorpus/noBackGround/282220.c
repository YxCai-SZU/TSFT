#include <stdbool.h>

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires ((len) >= 3 &&
     (0 <= (0) && (0) < ((len))) && 1 <= (arr)[0] && (arr)[0] <= 13 &&
     (0 <= (1) && (1) < ((len))) && 1 <= (arr)[1] && (arr)[1] <= 13 &&
     (0 <= (2) && (2) < ((len))) && 1 <= (arr)[2] && (arr)[2] <= 13);
  ensures \result == true <==> arr[0] + arr[1] >= arr[2];
*/
bool func(int *arr, int len) {
    int a, b, c;
    bool result;

    //@ assert ((len) >= 3 &&      (0 <= (0) && (0) < ((len))) && 1 <= (arr)[0] && (arr)[0] <= 13 &&      (0 <= (1) && (1) < ((len))) && 1 <= (arr)[1] && (arr)[1] <= 13 &&      (0 <= (2) && (2) < ((len))) && 1 <= (arr)[2] && (arr)[2] <= 13);
    //@ assert len >= 3;

    a = arr[0];
    b = arr[1];
    c = arr[2];

    //@ assert 1 <= a && a <= 13;
    //@ assert 1 <= b && b <= 13;
    //@ assert 1 <= c && c <= 13;

    if (a + b >= c) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == true <==> a + b >= c;
    return result;
}

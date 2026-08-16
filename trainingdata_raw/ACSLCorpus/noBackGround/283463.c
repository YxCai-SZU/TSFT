#include <stdbool.h>

/*@
  requires \valid(arr + (0 .. 2));
  requires ((3) == 3 &&
      \forall integer i; 0 <= i < (3) ==> 1 <= (arr)[i] && (arr)[i] <= 100);
  assigns \nothing;
  ensures \result == ((((arr)[0] < (arr)[1] && (arr)[1] < (arr)[2]) ? 1 : 0) == 1);
*/
bool func(int *arr) {
    int x0;
    int x1;
    int x2;
    bool result;

    x0 = arr[0];
    x1 = arr[1];
    x2 = arr[2];

    if (x0 < x1 && x1 < x2) {
        //@ assert x0 < x1 && x1 < x2;
        result = true;
    } else {
        //@ assert !(x0 < x1 && x1 < x2);
        result = false;
    }

    return result;
}

#include <stdbool.h>

/*@
  requires \valid_read(a + (0..2));
  requires 1 <= a[0] <= 100;
  requires 1 <= a[1] <= 100;
  requires 1 <= a[2] <= 100;
  ensures \result == true <==> ((a[1]) - (a[0]) == (a[2]) - (a[1]));
*/
bool func(const int* a) {
    int a0;
    int a1;
    int a2;
    bool result;

    a0 = a[0];
    a1 = a[1];
    a2 = a[2];

    //@ assert a1 - a0 >= -99 && a1 - a0 <= 99;

    if ((a1 - a0) == (a2 - a1)) {
        result = true;
    } else {
        result = false;
    }

    return result;
}

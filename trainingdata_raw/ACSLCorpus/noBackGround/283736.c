#include <stdbool.h>

/*@
  requires \valid(a + (0..2));
  requires (-100 <= (a[0]) && (a[0]) <= 100) && (-100 <= (a[1]) && (a[1]) <= 100) && (-100 <= (a[2]) && (a[2]) <= 100);
  assigns \nothing;
  ensures \result == (a[0] <= a[2] && a[2] <= a[1]);
*/
bool func(long long* a) {
    //@ assert (-100 <= (a[0]) && (a[0]) <= 100);
    //@ assert (-100 <= (a[1]) && (a[1]) <= 100);
    //@ assert (-100 <= (a[2]) && (a[2]) <= 100);
    return a[0] <= a[2] && a[2] <= a[1];
}

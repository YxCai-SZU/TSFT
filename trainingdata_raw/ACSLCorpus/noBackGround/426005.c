#include <stdbool.h>

/*@
  requires \valid_read(v + (0 .. 4));
  requires \forall integer i; 0 <= i < 5 ==> 0 <= v[i] <= 123;
  requires v[0] < v[1] && v[1] < v[2] && v[2] < v[3] && v[3] < v[4];
  requires 0 <= k <= 123;
  ensures \result == (k <= (v[4] - v[0]));
  assigns \nothing;
*/
bool func(int *v, int k) {
    //@ assert \forall integer i; 0 <= i < 5 ==> 0 <= v[i] <= 123;
    //@ assert v[0] < v[1] && v[1] < v[2] && v[2] < v[3] && v[3] < v[4];
    //@ assert 0 <= k <= 123;
    return k <= (v[4] - v[0]);
}

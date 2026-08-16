#include <stdbool.h>

/*@
  requires 0 <= a <= 100;
  requires 0 <= b <= 100;
  requires 0 <= c <= 100;
  ensures \result == true <==> ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
  assigns \nothing;
*/
bool can_distribute_evenly(int a, int b, int c) {
    //@ assert 0 <= a <= 100;
    //@ assert 0 <= b <= 100;
    //@ assert 0 <= c <= 100;
    return (a + b == c) || (a + c == b) || (b + c == a);
}

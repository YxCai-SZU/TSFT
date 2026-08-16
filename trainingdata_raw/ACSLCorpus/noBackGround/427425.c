#include <stdbool.h>

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == true <==> (((a) < (c) && (b) > (c)) || ((a) > (c) && (b) < (c)));
*/
bool can_pass_through(int a, int b, int c) {
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    return (a < c && b > c) || (a > c && b < c);
}

#include <stdbool.h>

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == true <==> (((a) < (b) && (b) < (c)) || ((a) > (b) && (b) > (c)));
  assigns \nothing;
*/
bool input_tuple(unsigned int a, unsigned int b, unsigned int c) {
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    return (a < b && b < c) || (a > b && b > c);
}

#include <stdbool.h>

/*@
  requires 0 <= a <= 100;
  requires 0 <= b <= 100;
  requires 0 <= c <= 100;
  requires a != b && b != c && a != c;
  ensures \result == true <==> (((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b)));
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    bool left;
    bool right;
    bool result;

    left = (a < c) && (c < b);
    right = (a > c) && (c > b);
    
    //@ assert left || right <==> (((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b)));
    
    result = left || right;
    return result;
}

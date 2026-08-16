#include <stdbool.h>

/*@
  requires 3 <= a <= 20;
  requires 3 <= b <= 20;
  ensures \result == a + b || \result == b * 2 - 1 || \result == a * 2 - 1;
  ensures \result >= 0;
*/
int func(int a, int b) {
    int max_ab;
    int min_ab;
    int result;
    
    // Calculate max and min
    if (a > b) {
        max_ab = a;
        min_ab = b;
    } else {
        max_ab = b;
        min_ab = a;
    }
    
    //@ assert (((a) >= (b) && (max_ab) == (a)) || ((b) >= (a) && (max_ab) == (b)));
    
    if (max_ab == a) {
        //@ assert max_ab == a;
        result = a + b;
    } else if (max_ab == b) {
        //@ assert max_ab == b;
        result = b + a;
    } else {
        // This case should never happen due to the predicate
        //@ assert max_ab == a || max_ab == b;
        result = -1;
    }
    
    return result;
}

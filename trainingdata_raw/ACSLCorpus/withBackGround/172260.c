#include <stdbool.h>

/*@ predicate all_equal(integer a, integer b, integer c) = 
      a == b && b == c;
*/
/*@ predicate two_equal(integer a, integer b, integer c) = 
      (a == b || b == c || a == c) && !(a == b && b == c);
*/
/*@ predicate all_different(integer a, integer b, integer c) = 
      a != b && b != c && a != c;
*/

/*@
  requires -100 <= a <= 100;
  requires -100 <= b <= 100;
  requires -100 <= c <= 100;
  ensures all_equal(a, b, c) ==> \result == 1;
  ensures two_equal(a, b, c) ==> \result == 2;
  ensures all_different(a, b, c) ==> \result == 3;
*/
int func(int a, int b, int c)
{
    int x = 0;
    
    if (a == b) {
        x += 1;
    }
    if (b == c) {
        x += 1;
    }
    if (a == c) {
        x += 1;
    }
    
    //@ assert x == 3 || x == 2 || x == 1 || x == 0;
    
    if (x == 3) {
        return 1;
    } else if (x > 0) {
        //@ assert x == 2 || x == 1;
        //@ assert a == b || b == c || a == c;
        return 2;
    } else {
        //@ assert a != b && b != c && a != c;
        return 3;
    }
}

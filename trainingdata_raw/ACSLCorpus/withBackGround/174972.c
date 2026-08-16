#include <stdbool.h>

/*@ predicate opposite_signs(integer a, integer b) =
      (a > 0 && b < 0) || (a < 0 && b > 0);
*/

/*@
  requires -1000 <= a <= 1000;
  requires -1000 <= b <= 1000;
  ensures \result == true <==> opposite_signs(a, b);
*/
bool func(int a, int b)
{
    //@ assert -1000 <= a <= 1000;
    //@ assert -1000 <= b <= 1000;
    
    if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
        //@ assert opposite_signs(a, b);
        return true;
    } else {
        //@ assert !opposite_signs(a, b);
        return false;
    }
}

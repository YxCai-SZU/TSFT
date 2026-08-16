#include <stdbool.h>

/*@ predicate condition_holds(integer a, integer b, integer x) =
      a <= x && a + b >= x;
*/

/*@
  requires 1 <= a && a <= 100;
  requires 1 <= b && b <= 100;
  requires 1 <= x && x <= 200;
  ensures \result == (a <= x && a + b >= x);
*/
bool func(int a, int b, int x)
{
    bool result;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= x && x <= 200;
    
    if (a <= x && a + b >= x) {
        result = true;
        //@ assert condition_holds(a, b, x);
    } else {
        //@ assert !condition_holds(a, b, x);
        result = false;
    }
    
    //@ assert result == (a <= x && a + b >= x);
    return result;
}

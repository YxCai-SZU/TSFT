#include <stdbool.h>

/*@ predicate is_possible(integer a, integer b, integer x) =
      x >= a && x <= a + b;
*/

/*@
  requires 0 <= a <= 50;
  requires 0 <= b <= 50;
  requires 0 <= x <= 50;
  ensures \result == (x >= a && x <= a + b);
*/
bool is_possible_to_have_exactly_x_cats(int a, int b, int x)
{
    bool result;
    //@ assert 0 <= a <= 50;
    //@ assert 0 <= b <= 50;
    //@ assert 0 <= x <= 50;
    
    if (x < a) {
        result = false;
        //@ assert !(x >= a && x <= a + b);
    } else {
        //@ assert x >= a;
        result = (x <= (a + b));
        //@ assert result == (x >= a && x <= a + b);
    }
    
    return result;
}

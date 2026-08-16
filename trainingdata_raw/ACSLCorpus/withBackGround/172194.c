#include <stdbool.h>

/*@ predicate is_valid_range(integer x, integer y) =
      1 <= x && x < y && y <= 10000;
*/

/*@ lemma product_bounds_x:
      \forall integer x; 1 <= x <= 10000 ==> x * 5 <= 50000;
*/

/*@ lemma product_bounds_y:
      \forall integer y; 1 <= y <= 10000 ==> y * 3 <= 30000;
*/

/*@ requires is_valid_range(x, y);
    ensures \result == (x * 5 <= y * 3);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert x * 5 <= 50000;
    //@ assert y * 3 <= 30000;
    
    result = (x * 5 <= y * 3);
    return result;
}

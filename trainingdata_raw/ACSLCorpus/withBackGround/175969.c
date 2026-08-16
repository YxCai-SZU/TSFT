#include <stdbool.h>

/*@ predicate is_ordered(integer a, integer b, integer c) = 
      a < b && b < c;
*/

/*@ requires a >= -2147483648 && a <= 2147483647;
    requires b >= -2147483648 && b <= 2147483647;
    requires c >= -2147483648 && c <= 2147483647;
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c) {
    bool result;
    
    //@ assert a < b && b < c ==> (a < b && b < c);
    
    result = (a < b && b < c);
    return result;
}

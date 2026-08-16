#include <stdbool.h>

/*@ predicate is_ordered(integer a, integer b, integer c) =
      (a < b && b < c) || (a > b && b > c);
*/

/*@ requires 0 <= a && a < 100;
    requires 0 <= b && b < 100;
    requires 0 <= c && c < 100;
    ensures \result <==> is_ordered(a, b, c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 0 <= a && a < 100;
    //@ assert 0 <= b && b < 100;
    //@ assert 0 <= c && c < 100;
    
    result = (a < b && b < c) || (a > b && b > c);
    return result;
}

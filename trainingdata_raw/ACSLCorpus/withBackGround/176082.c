#include <stdbool.h>

/*@ predicate is_between(integer a, integer b, integer c) =
      (b < c && c < a) || (a < c && c < b);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires a != b;
    ensures \result == true <==> is_between(a, b, c);
*/
bool func(int a, int b, int c) {
    bool result;
    
    //@ assert a != b;
    
    result = (b < c && c < a) || (a < c && c < b);
    
    return result;
}

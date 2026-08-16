#include <stdbool.h>

/*@
    predicate is_less_than(integer a, integer b, integer c) = 
        a < b && b < c;
*/

/*@
    requires a > -2147483648;
    requires b > -2147483648;
    requires c > -2147483648;
    requires a < 2147483647;
    requires b < 2147483647;
    requires c < 2147483647;
    ensures \result == (a < b && b < c);
*/
bool func(int a, int b, int c) {
    bool result;
    
    //@ assert a > -2147483648 && b > -2147483648 && c > -2147483648;
    
    if (a < b && b < c) {
        //@ assert a < b && b < c;
        result = true;
    } else {
        //@ assert !(a < b && b < c);
        result = false;
    }
    
    return result;
}

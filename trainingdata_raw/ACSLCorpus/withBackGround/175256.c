#include <stdbool.h>

/*@
    predicate is_valid_params(integer a, integer b, integer c) =
        1 <= a <= 10 && 1 <= b <= 10 && 1 <= c <= 10;

    predicate result_condition(integer a, integer b, integer c, bool result) =
        result == ((a == 5 && b == 5 && c == 7) ||
                   (a == 5 && b == 7 && c == 5) ||
                   (a == 7 && b == 5 && c == 5));
 */

/*@
    requires is_valid_params(a, b, c);
    ensures result_condition(a, b, c, \result);
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    int count = 0;
    
    //@ assert is_valid_params(a, b, c);
    
    if (a == 5) {
        count += 1;
    }
    if (b == 5) {
        count += 1;
    }
    if (c == 5) {
        count += 1;
    }
    
    if (count == 2 && (a == 7 || b == 7 || c == 7)) {
        //@ assert count == 2 && (a == 7 || b == 7 || c == 7);
        return true;
    }
    
    //@ assert count != 2 || !(a == 7 || b == 7 || c == 7);
    return false;
}

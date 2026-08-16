#include <stdbool.h>

/*@ predicate is_min(integer a, integer b, integer c) =
    (a < b && a < c) || (b < c && b < a) || (c < a && c < b);
*/

/*@
    requires a > 0 && b > 0 && c > 0;
    requires a <= 10 && b <= 10 && c <= 10;
    ensures \result == true <==> is_min(a, b, c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    //@ assert a > 0 && b > 0 && c > 0;
    //@ assert a <= 10 && b <= 10 && c <= 10;
    
    if ((a < b && a < c) || (b < c && b < a) || (c < a && c < b)) {
        result = true;
        //@ assert is_min(a, b, c);
    } else {
        result = false;
        //@ assert !is_min(a, b, c);
    }
    
    return result;
}

#include <stdbool.h>

/*@
    predicate is_sum(integer a, integer b, integer c, bool result) =
        (a >= 1 && a <= 100) &&
        (b >= 1 && b <= 100) &&
        (c >= 1 && c <= 100) &&
        (result <==> (a + b == c || b + c == a || c + a == b));
*/

/*@
    requires a >= 1 && a <= 100;
    requires b >= 1 && b <= 100;
    requires c >= 1 && c <= 100;
    ensures \result <==> (a + b == c || b + c == a || c + a == b);
    assigns \nothing;
*/
bool is_sum(int a, int b, int c)
{
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert c >= 1 && c <= 100;
    
    bool result;
    result = (a + b == c) || (b + c == a) || (c + a == b);
    
    //@ assert is_sum(a, b, c, result);
    return result;
}

#include <stdbool.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 16 && 1 <= m <= 16 && n + m <= 16;

    predicate both_small(integer n, integer m) =
        n <= 8 && m <= 8;
*/

/*@
    requires valid_range(n, m);
    ensures \result == true <==> both_small(n, m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    bool result;

    //@ assert valid_range(n, m);
    
    if (n <= 8 && m <= 8) {
        //@ assert both_small(n, m);
        result = true;
    } else {
        //@ assert !both_small(n, m);
        result = false;
    }

    return result;
}

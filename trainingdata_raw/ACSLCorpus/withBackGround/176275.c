#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 3 <= x && x <= 20;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result >= 0 && \result <= 40;
    assigns \nothing;
*/
int func(int a, int b)
{
    int max_value;
    
    if (a > b) {
        max_value = a;
    } else {
        max_value = b;
    }
    
    //@ assert max_value >= 3 && max_value <= 20;
    
    return 2 * max_value;
}

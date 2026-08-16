#include <stdbool.h>

/*@
    predicate is_in_range(integer x) = 15 <= x && x <= 20;
    predicate is_target(integer x) = x == 16 || x == 17 || x == 18 || x == 19;
*/


bool func(unsigned int x)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert is_in_range(x);
    result = (x == 16 || x == 17 || x == 18 || x == 19);
    //@ assert result == true <==> is_target(x);
    return result;
}

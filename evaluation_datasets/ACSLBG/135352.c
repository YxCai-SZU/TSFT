#include <stdbool.h>

/*@
    predicate is_valid_range(integer v) =
        0 <= v && v <= 10;
*/


bool func(int x, int y)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 0 <= x * x && x * x <= 100;
    result = (x * x <= y);
    return result;
}

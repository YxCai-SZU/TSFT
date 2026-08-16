#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer rgb_value(integer r, integer g, integer b) = 100 * r + 10 * g + b;

    lemma rgb_bounds:
        \forall integer r, g, b;
            valid_range(r) && valid_range(g) && valid_range(b) ==> 
            111 <= rgb_value(r, g, b) <= 999;
*/

/*@
    requires 1 <= r <= 9;
    requires 1 <= g <= 9;
    requires 1 <= b <= 9;
    ensures \result == ((100 * r + 10 * g + b) % 4 == 0);
*/
bool func(unsigned int r, unsigned int g, unsigned int b)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int intermediate;
    unsigned int final_value;

    //@ assert 100 <= 100 * r <= 900;
    //@ assert 10 <= 10 * g <= 90;
    //@ assert 1 <= b <= 9;
    //@ assert 111 <= 100 * r + 10 * g + b <= 999;

    intermediate = 100 * r + 10 * g;
    final_value = intermediate + b;
    result = (final_value % 4 == 0);
    
    return result;
}

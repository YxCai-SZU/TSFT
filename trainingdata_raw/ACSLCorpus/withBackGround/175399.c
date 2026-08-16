#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer calculate_sum(integer b, integer c) = b * 10 + c;
    logic integer calculate_diff(integer sum, integer a) = sum - a;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    ensures \result == (calculate_sum(b, c) - a >= 0);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    int diff;

    sum = b * 10 + c;
    diff = (int)sum - (int)a;

    //@ assert diff == calculate_sum(b, c) - a;

    return diff >= 0;
}

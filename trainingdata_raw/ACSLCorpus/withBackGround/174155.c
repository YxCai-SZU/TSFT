#include <stdint.h>

/*@ predicate in_range(integer v) = 0 <= v <= 50; */
/*@ logic integer sum(integer a, integer b, integer c) = a + b + c; */

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result >= 0;
    ensures \result <= sum(a, b, c);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t result;
    int64_t min_val;

    result = 0;

    if (c > a + b + 1)
    {
        result = a + b + 1 + 1;
    }
    else if (c == a + b + 1)
    {
        result = a + b;
    }
    else
    {
        result = c;
    }

    if (a < b)
    {
        min_val = a;
    }
    else
    {
        min_val = b;
    }

    if (min_val > result)
    {
        return result;
    }
    else
    {
        //@ assert min_val == a || min_val == b;
        //@ assert min_val <= sum(a, b, c);
        return min_val;
    }
}

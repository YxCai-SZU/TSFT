#include <stdbool.h>

/*@ predicate in_range(integer x) = 1 <= x <= 13; */

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == (a + b + c <= 21);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    bool result;

    sum = a + b + c;
    result = true;

    if (sum > 21)
    {
        result = false;
    }
    else
    {
        //@ assert a + b + c <= 21;
    }

    return result;
}

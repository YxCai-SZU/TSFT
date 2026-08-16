#include <stdbool.h>

/*@
    predicate is_in_range(integer x) = 1 <= x <= 10000;
*/

/*@
    requires is_in_range(n) && is_in_range(m);
    ensures \result == (n > m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    bool result;
    //@ assert n > m ==> n > m;
    result = n > m;
    return result;
}

/*@
    requires is_in_range(n) && is_in_range(m);
    ensures \result == (n >= m);
    assigns \nothing;
*/
bool func2(unsigned int n, unsigned int m)
{
    bool result;
    //@ assert n >= m ==> n >= m;
    result = n >= m;
    return result;
}

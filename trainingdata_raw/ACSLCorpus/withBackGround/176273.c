#include <stdbool.h>

/*@ predicate is_in_range(integer x) = 1 <= x <= 100; */

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c);
    ensures \result == (b - a == c - b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert c >= 1 && c <= 100;
    
    //@ assert b - a >= -99 && b - a <= 99;
    //@ assert c - b >= -99 && c - b <= 99;

    //@ assert (b - a == c - b) == (b - a == c - b);
    
    result = (b - a == c - b);
    return result;
}

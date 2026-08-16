#include <stdbool.h>

/*@ predicate is_valid_s(integer s) = 10 <= s && s <= 99; */

/*@
    requires is_valid_s(s);
    ensures \result == (s / 10 == 9 || s % 10 == 9);
    assigns \nothing;
*/
bool func(unsigned int s)
{
    // Variable declarations at top of scope
    bool s1;
    bool s2;
    bool result;

    //@ assert s / 10 <= 9;
    //@ assert s % 10 <= 9;

    s1 = (s / 10) == 9;
    s2 = (s % 10) == 9;
    result = s1 || s2;
    
    return result;
}

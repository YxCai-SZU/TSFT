#include <stdbool.h>

/*@
    predicate has_nine(integer s) =
        s % 10 == 9 || (s / 10) % 10 == 9;
*/

/*@
    requires 10 <= s <= 99;
    ensures \result == (s % 10 == 9 || (s / 10) % 10 == 9);
    assigns \nothing;
*/
bool func(unsigned long long s)
{
    bool result;

    //@ assert 10 <= s <= 99;
    if (s % 10 == 9 || (s / 10) % 10 == 9)
    {
        //@ assert s % 10 == 9 || (s / 10) % 10 == 9;
        result = true;
    }
    else
    {
        //@ assert s % 10 != 9 && (s / 10) % 10 != 9;
        result = false;
    }
    //@ assert result == (s % 10 == 9 || (s / 10) % 10 == 9);
    return result;
}

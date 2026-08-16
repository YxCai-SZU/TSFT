#include <stdbool.h>

/*@
    predicate is_valid_s(integer s) = 100 <= s && s <= 999;

    logic integer has_seven(integer s) =
        (s / 100 == 7 ? 1 : 0) + 
        ((s / 10) % 10 == 7 ? 1 : 0) + 
        (s % 10 == 7 ? 1 : 0);
*/

/*@
    requires is_valid_s(s);
    ensures \result == (has_seven(s) > 0);
    assigns \nothing;
*/
bool func(unsigned int s)
{
    unsigned int s_100;
    unsigned int s_10;
    unsigned int s_1;
    bool result;

    //@ assert s / 100 <= 9;
    s_100 = s / 100;
    //@ assert (s / 10) % 10 <= 9;
    s_10 = (s / 10) % 10;
    //@ assert s % 10 <= 9;
    s_1 = s % 10;

    result = (s_100 == 7) || (s_10 == 7) || (s_1 == 7);
    return result;
}

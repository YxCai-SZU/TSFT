#include <stdbool.h>

/*@
    predicate valid_vec(int *s, integer len) =
        len >= 3 &&
        1 <= s[0] && s[0] <= 100 &&
        1 <= s[1] && s[1] <= 100 &&
        1 <= s[2] && s[2] <= 100;

    logic integer arithmetic_property(int *s) =
        (s[1] - s[0] == s[2] - s[1]) ? 1 : 0;
*/

/*@
    requires \valid(s+(0..2));
    requires valid_vec(s, 3);
    ensures \result == (arithmetic_property(s) == 1);
    assigns \nothing;
*/
bool f(int *s)
{
    bool result;

    //@ assert 1 <= s[0] && s[0] <= 100;
    //@ assert 1 <= s[1] && s[1] <= 100;
    //@ assert 1 <= s[2] && s[2] <= 100;
    //@ assert 3 >= 3;

    result = (s[1] - s[0] == s[2] - s[1]);
    return result;
}

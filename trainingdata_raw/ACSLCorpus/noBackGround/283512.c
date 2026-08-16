#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    ensures ((\result) == (6 - ((a)) - ((b))) &&
        ((\result) == 1 || (\result) == 2 || (\result) == 3) &&
        (\result) != (a) && (\result) != (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    //@ assert (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    result = 6 - a - b;
    //@ assert result == (6 - (a) - (b));
    //@ assert result == 1 || result == 2 || result == 3;
    return result;
}

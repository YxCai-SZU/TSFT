#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    ensures \result + a + b == 6;
    ensures 1 <= \result <= 3;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    //@ assert (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    result = 6 - a - b;
    //@ assert result == (6 - (a) - (b));
    //@ assert result + a + b == 6;
    //@ assert 1 <= result <= 3;
    return result;
}

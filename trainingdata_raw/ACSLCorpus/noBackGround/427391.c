#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= (n) * 2);
    ensures \result == ((n) - ((x) - 1));
    assigns \nothing;
*/
int func(int n, int x)
{
    int result;
    //@ assert (1 <= (n) && (n) <= 100 &&         1 <= (x) && (x) <= (n) * 2);
    result = n - (x - 1);
    //@ assert result == ((n) - ((x) - 1));
    return result;
}

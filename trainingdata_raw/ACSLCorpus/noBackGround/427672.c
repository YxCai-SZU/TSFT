#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (2 * (n));
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n)
{
    int result;

    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert (2 * (n)) >= 0;

    result = 2 * n;

    //@ assert result == (2 * (n));
    //@ assert result >= 0;

    return result;
}

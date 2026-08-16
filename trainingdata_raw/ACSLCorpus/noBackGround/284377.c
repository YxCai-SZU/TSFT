#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures ((\result) == ((a) > (b) || ((a) < (b) && (b) < 10)));
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    result = a > b || (a < b && b < 10);
    //@ assert ((result) == ((a) > (b) || ((a) < (b) && (b) < 10)));
    return result;
}

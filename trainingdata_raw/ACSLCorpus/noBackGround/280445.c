#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100 && 1 <= (x) && (x) <= 100000);
    assigns \nothing;
    ensures \result == (500 * k >= x);
*/
bool func(unsigned int k, unsigned int x)
{
    bool result;
    //@ assert (1 <= (k) && (k) <= 100 && 1 <= (x) && (x) <= 100000);
    result = (500U * k) >= x;
    //@ assert result == (500 * k >= x);
    return result;
}

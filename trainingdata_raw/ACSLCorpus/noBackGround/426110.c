#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (x) <= 100);
    ensures \result == (b <= x && x <= a + b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    bool result;
    //@ assert b <= x && x <= a + b ==> (b <= x && x <= a + b);
    result = (b <= x) && (x <= a + b);
    return result;
}

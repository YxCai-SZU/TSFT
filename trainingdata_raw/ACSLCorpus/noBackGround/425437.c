#include <stdbool.h>

/*@
    requires (1 <= (a) <= 13) && (1 <= (b) <= 13) && (1 <= (c) <= 13);
    ensures \result == (a + b + c < 22);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    unsigned long total;

    total = a + b + c;

    if (total >= 22)
    {
        //@ assert total >= 22;
        return false;
    }
    else
    {
        //@ assert total < 22;
        return true;
    }
}

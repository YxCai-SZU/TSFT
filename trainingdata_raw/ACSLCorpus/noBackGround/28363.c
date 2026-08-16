#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (c) <= 100);
    ensures ((\result) == (((a) < (c)) && ((b) > (c))));
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    // Variable declarations at top of scope
    bool result;

    // Proof assertions
    //@ assert (0 <= (a) <= 100);
    //@ assert (0 <= (b) <= 100);
    //@ assert (0 <= (c) <= 100);

    result = (a < c) && (b > c);
    return result;
}

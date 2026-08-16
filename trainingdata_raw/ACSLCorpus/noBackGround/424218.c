#include <stdbool.h>

/*@
    requires (1 <= (a) <= 13) && (1 <= (b) <= 13) && (1 <= (c) <= 13);
    ensures \result == (a + b + c < 22);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (1 <= (a) <= 13);
    //@ assert (1 <= (b) <= 13);
    //@ assert (1 <= (c) <= 13);
    //@ assert 3 <= a + b + c <= 39;

    result = (a + b + c) < 22;

    //@ assert result == (a + b + c < 22);
    return result;
}

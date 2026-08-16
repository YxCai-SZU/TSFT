#include <stdbool.h>

/*@
    requires (1 <= (A) <= 100);
    requires (1 <= (B) <= 100);
    requires (1 <= (C) <= 100);
    ensures \result == (((A) + (B) + (C)) >= 22);
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    // Variable declarations at top of scope
    bool result;

    // Proof block assertions
    //@ assert (1 <= (A) <= 100);
    //@ assert (1 <= (B) <= 100);
    //@ assert (1 <= (C) <= 100);

    result = (A + B + C) >= 22;
    return result;
}

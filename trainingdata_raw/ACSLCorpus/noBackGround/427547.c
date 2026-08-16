#include <stdbool.h>

/*@
    requires (1 <= (A) <= 100) && ((A) == (integer)(A));
    requires (1 <= (B) <= 100) && ((B) == (integer)(B));
    requires (1 <= (C) <= 100) && ((C) == (integer)(C));
    ensures \result == (C - B == B - A);
*/
bool func(long A, long B, long C)
{
    // Variable declarations at top of scope
    bool result;

    // Proof assertions
    //@ assert ((A) == (integer)(A));
    //@ assert ((B) == (integer)(B));
    //@ assert ((C) == (integer)(C));

    result = (C - B == B - A);
    return result;
}

#include <stdbool.h>

/*@
    requires (2 <= (N) && (N) <= 100 &&
        1 <= (A) && (A) < (B) && (B) <= (N));
    ensures \result == (A != B);
    assigns \nothing;
*/
bool func(unsigned int N, unsigned int A, unsigned int B)
{
    // Variable declarations at the top
    bool result;

    if (A != B)
    {
        //@ assert A != B;
        result = true;
    }
    else
    {
        //@ assert A == B;
        result = false;
    }

    return result;
}

#include <limits.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100);
    ensures \result == A * B;
    assigns \nothing;
*/
int func(int A, int B)
{
    // Variable declarations at top of scope
    int result;

    //@ assert (1 <= (A) <= 100);
    //@ assert (1 <= (B) <= 100);
    //@ assert A * B <= 100 * 100;
    //@ assert A * B >= 1 * 1;

    result = A * B;
    return result;
}

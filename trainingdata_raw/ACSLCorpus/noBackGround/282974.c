#include <stdbool.h>

/*@
    requires (1 <= (N) <= 1000);
    requires (0 <= (A) <= 1000);
    ensures \result == ((((N) - 500) <= (A) ? 1 : 0) == 1);
*/
bool func(int N, int A)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= N <= 1000;
    //@ assert 0 <= A <= 1000;

    result = (N - 500) <= A;
    return result;
}

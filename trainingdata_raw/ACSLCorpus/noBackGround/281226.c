#include <limits.h>

/*@
    requires (2 <= (N) <= 100) && (2 <= (M) <= 100);
    ensures \result == (((N) - 1) * ((M) - 1));
    assigns \nothing;
*/
int func(int N, int M)
{
    // Variable declarations at scope top
    int result;

    //@ assert N > 1 && N <= 100;
    //@ assert M > 1 && M <= 100;
    //@ assert (((N) - 1) * ((M) - 1)) <= 99 * 99;

    result = (N - 1) * (M - 1);
    return result;
}

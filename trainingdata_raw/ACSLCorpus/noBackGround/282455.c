#include <stdint.h>

/*@
    requires (2 <= (N) && (N) <= 100 &&
        2 <= (M) && (M) <= 100);
    ensures \result == (((N) - 1) * ((M) - 1));
    assigns \nothing;
*/
int64_t func(int64_t N, int64_t M)
{
    // Variable declarations at scope top
    int64_t result;

    //@ assert N > 1 && M > 1;
    //@ assert N <= 100 && M <= 100;
    //@ assert (N - 1) * (M - 1) >= 0;
    //@ assert (N - 1) * (M - 1) <= 99 * 99;

    result = (N - 1) * (M - 1);
    return result;
}

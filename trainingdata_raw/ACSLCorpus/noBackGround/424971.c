#include <stddef.h>

/*@
    requires (1 <= (N) && 1 <= (M) && (N) <= 1000000000000 && (M) <= 1000000000000);
    assigns \nothing;
    ensures 0 <= \result && \result <= N + M;
*/
size_t func(size_t N, size_t M)
{
    size_t min_val;
    size_t result;
    size_t remainder;

    //@ assert (1 <= (N) && 1 <= (M) && (N) <= 1000000000000 && (M) <= 1000000000000);

    if (N < M)
    {
        min_val = N;
    }
    else
    {
        min_val = M;
    }

    result = min_val;
    remainder = N + M - 2 * min_val;
    result += remainder / 4;

    //@ assert result == ((((N)) < ((M)) ? ((N)) : ((M))) + ((N) + (M) - 2 * (((N)) < ((M)) ? ((N)) : ((M)))) / 4);
    //@ assert result <= N + M;

    return result;
}

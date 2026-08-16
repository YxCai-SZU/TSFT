#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 1000000000000 &&
        1 <= (M) && (M) <= 1000000000000);
    ensures \result <= N + M / 2;
    assigns \nothing;
*/
uint64_t func(uint64_t N, uint64_t M)
{
    uint64_t min_val;
    uint64_t result;

    //@ assert (1 <= (N) && (N) <= 1000000000000 &&         1 <= (M) && (M) <= 1000000000000);

    if (N < M / 2)
    {
        min_val = N;
        //@ assert min_val == N;
    }
    else
    {
        min_val = M / 2;
        //@ assert min_val == M / 2;
    }

    //@ assert min_val == ((N) < (M) / 2 ? (N) : (M) / 2);

    if (N > M / 2)
    {
        result = M / 4 + (min_val - M / 4);
    }
    else
    {
        result = M / 4;
    }

    //@ assert result <= N + M / 2;
    return result;
}

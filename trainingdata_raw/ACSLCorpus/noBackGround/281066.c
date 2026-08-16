#include <stdint.h>

/*@
    requires (1 <= (N) <= 100 &&
        1 <= (M) <= 100 &&
        (N) <= (M) * 2 &&
        (M) * 2 + 1 - (N) >= 0);
    ensures \result == ((M) * 2 + 1 - (N));
    assigns \nothing;
*/
int32_t func(int32_t N, int32_t M)
{
    // Variable declarations at scope top
    int32_t result;

    //@ assert 1 <= M && M <= 100;
    //@ assert M * 2 <= 200;
    //@ assert M * 2 + 1 <= 201;
    //@ assert M * 2 + 1 - N >= 0;

    result = M * 2 + 1 - N;
    return result;
}

#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 1000000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (((N) % 100) * 21) <= N;
    ensures \result == 0 ==> (((N) % 100) * 21) > N;
*/
uint32_t func(uint32_t N)
{
    uint32_t result;

    //@ assert (1 <= (N) && (N) <= 1000000);
    //@ assert (((N) % 100) * 21) == (N % 100) * 21;

    if ((N % 100) * 21 <= N)
    {
        //@ assert (((N) % 100) * 21) <= N;
        result = 1;
    }
    else
    {
        //@ assert (((N) % 100) * 21) > N;
        result = 0;
    }

    //@ assert result == 1 || result == 0;
    //@ assert result == 1 ==> (((N) % 100) * 21) <= N;
    //@ assert result == 0 ==> (((N) % 100) * 21) > N;
    return result;
}

#include <stdint.h>
/*@
    requires (1 <= (N) && (N) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (((N) % 100) * 21) < N;
    ensures \result == 0 ==> (((N) % 100) * 21) >= N;
*/
uint32_t func(uint32_t N)
{
    uint32_t num;
    uint32_t div;

    //@ assert (1 <= (N) && (N) <= 100000);
    //@ assert ((N) / 100) <= 1000;
    num = N % 100;
    div = N / 100;

    if (num * 21 < N)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

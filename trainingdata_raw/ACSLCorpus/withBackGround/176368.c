#include <stdint.h>

/*@
    predicate valid_range(integer N) = 1 <= N && N <= 10000;

    logic integer remainder_calc(integer N) = 
        N >= 0 ? N % 1000 : (-N) % 1000;

    logic integer result_spec(integer N) = 
        remainder_calc(N) == 0 ? 0 : 1000 - remainder_calc(N);
*/

/*@
    requires valid_range(N);
    ensures (N % 1000 == 0 ==> \result == 0);
    ensures (N % 1000 != 0 ==> \result == 1000 - N % 1000);
*/
int32_t func(int32_t N)
{
    uint32_t N_unsigned;
    uint32_t remainder;
    int32_t result;

    //@ assert valid_range(N);
    if (N < 0)
    {
        N_unsigned = (uint32_t)(-N);
    }
    else
    {
        N_unsigned = (uint32_t)N;
    }

    remainder = N_unsigned % 1000U;

    if (remainder == 0U)
    {
        result = 0;
        //@ assert remainder_calc(N) == 0;
        return result;
    }
    else
    {
        //@ assert remainder_calc(N) != 0;
        //@ assert remainder_calc(N) == (int)remainder;
        result = 1000 - (int32_t)remainder;
        return result;
    }
}

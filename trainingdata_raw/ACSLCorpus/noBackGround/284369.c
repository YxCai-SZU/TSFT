#include <stdint.h>

/*@
    requires (1 <= (N) <= 1000000000);
    ensures \result <= (2 * ((N) / 11) + 2);
    assigns \nothing;
*/
uint64_t func(uint64_t N)
{
    uint64_t result;
    uint64_t temp_N;
    
    result = (N / 11) * 2;
    temp_N = N % 11;
    
    //@ assert result == 2 * (N / 11);
    
    if (temp_N > 0)
    {
        result += 1;
        //@ assert result == 2 * (N / 11) + 1;
    }
    
    if (temp_N > 5)
    {
        result += 1;
        //@ assert result == 2 * (N / 11) + (temp_N > 0 ? 1 : 0) + 1;
    }
    
    //@ assert result <= (2 * ((N) / 11) + 2);
    return result;
}

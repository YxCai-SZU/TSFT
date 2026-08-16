#include <stdint.h>

/*@
    requires (1 <= (N) <= 1000000000);
    ensures \result <= 2 * (N / 11) + 2;
    assigns \nothing;
*/
uint64_t func(uint64_t N)
{
    uint64_t result;
    uint64_t remainder;

    //@ assert (1 <= (N) <= 1000000000);
    
    result = (N / 11) * 2;
    remainder = N % 11;
    
    if (remainder == 0)
    {
        //@ assert (((N) % 11 == 0) ? 0 :         ((N) % 11 < 7) ? 1 : 2) == 0;
        result += 0;
    }
    else if (remainder < 7)
    {
        //@ assert (((N) % 11 == 0) ? 0 :         ((N) % 11 < 7) ? 1 : 2) == 1;
        result += 1;
    }
    else
    {
        //@ assert (((N) % 11 == 0) ? 0 :         ((N) % 11 < 7) ? 1 : 2) == 2;
        result += 2;
    }
    
    //@ assert result == (((((N)) / 11) * 2) + ((((N)) % 11 == 0) ? 0 :         (((N)) % 11 < 7) ? 1 : 2));
    //@ assert result <= 2 * (N / 11) + 2;
    
    return result;
}

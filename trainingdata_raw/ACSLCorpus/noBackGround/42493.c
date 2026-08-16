#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures (n % 1000 == 0 ==> \result == 0) && (n % 1000 != 0 ==> \result == 1000 - n % 1000);
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    uint64_t n_unsigned;
    uint64_t remainder;
    uint64_t result;

    //@ assert (1 <= (n) && (n) <= 10000);
    n_unsigned = (n < 0) ? (uint64_t)(-n) : (uint64_t)n;
    //@ assert n_unsigned == (n < 0 ? (uint64_t)(-n) : (uint64_t)n);

    remainder = n_unsigned % 1000;
    //@ assert remainder == n_unsigned % 1000;

    result = (remainder == 0) ? 0 : (1000 - remainder);
    //@ assert result == (remainder == 0 ? 0 : 1000 - remainder);

    //@ assert result == 0 || result == 1000 - remainder;

    if (n < 0)
    {
        //@ assert result == 0 || result == 1000 - remainder;
        return -(int64_t)result;
    }
    else
    {
        //@ assert result == 0 || result == 1000 - remainder;
        return (int64_t)result;
    }
}

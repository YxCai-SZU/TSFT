#include <stdint.h>
/*@
    requires 1 <= N <= 100000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (N % 100) * 21 + (N / 100) >= 1000;
    ensures \result == 0 ==> (N % 100) * 21 + (N / 100) < 1000;
*/
uint32_t func(uint32_t N)
{
    uint32_t result;
    uint32_t tmp;

    //@ assert 1 <= N <= 100000;
    tmp = (N % 100) * 21 + (N / 100);
    
    if (tmp >= 1000) {
        //@ assert tmp >= 1000;
        //@ assert (((N) % 100) * 21 + ((N) / 100) >= 1000);
        result = 1;
    } else {
        //@ assert tmp < 1000;
        //@ assert !(((N) % 100) * 21 + ((N) / 100) >= 1000);
        result = 0;
    }
    
    //@ assert result == 1 || result == 0;
    //@ assert result == 1 ==> tmp >= 1000;
    //@ assert result == 0 ==> tmp < 1000;
    return result;
}

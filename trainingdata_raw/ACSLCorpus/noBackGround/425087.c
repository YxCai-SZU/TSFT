#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100 && 1 <= (k) && (k) <= 100);
    ensures \result == ((n) % (k) == 0 ? 0 : 1);
    ensures \result >= 0 && \result < 2;
*/
int32_t func(uint32_t n, uint32_t k)
{
    int32_t result;
    //@ assert (1 <= (n) && (n) <= 100 && 1 <= (k) && (k) <= 100);
    
    if (n % k == 0)
    {
        result = 0;
        //@ assert result == ((n) % (k) == 0 ? 0 : 1);
    }
    else
    {
        //@ assert 1 >= 0 && 1 < 2;
        result = 1;
        //@ assert result == ((n) % (k) == 0 ? 0 : 1);
    }
    
    //@ assert result >= 0 && result < 2;
    return result;
}

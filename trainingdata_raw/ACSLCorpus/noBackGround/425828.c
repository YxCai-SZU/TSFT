#include <stdint.h>

/*@
    requires 1 <= n && n <= 100;
    ensures \result >= 0;
    ensures \result == ((((n)) * 800) - ((((n)) / 15) * 200));
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t result;
    uint32_t tmp1;
    uint32_t tmp2;
    uint32_t tmp3;

    //@ assert (1 <= (n) && (n) <= 100);
    
    tmp1 = n * 800U;
    //@ assert tmp1 == ((n) * 800);
    
    tmp2 = n / 15U;
    //@ assert tmp2 == n / 15;
    
    tmp3 = tmp2 * 200U;
    //@ assert tmp3 == (((n) / 15) * 200);
    
    result = (int32_t)(tmp1 - tmp3);
    //@ assert result == ((((n)) * 800) - ((((n)) / 15) * 200));
    
    return result;
}

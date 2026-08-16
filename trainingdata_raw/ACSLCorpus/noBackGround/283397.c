#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (n % 100) * 21 <= n;
    ensures \result == 0 ==> (n % 100) * 21 > n;
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t a;
    uint32_t b;
    uint32_t result;

    //@ assert (1 <= (n) && (n) <= 100000);
    a = n / 100;
    b = n % 100;
    
    //@ assert b == n % 100;
    //@ assert 0 <= b < 100;
    //@ assert b * 21 <= 100 * 21;
    
    if (b * 21 <= n)
    {
        //@ assert (n % 100) * 21 <= n;
        result = 1;
    }
    else
    {
        //@ assert (n % 100) * 21 > n;
        result = 0;
    }
    
    return result;
}

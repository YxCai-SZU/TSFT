#include <stdint.h>

/*@
    requires (100 <= (n) && (n) <= 999);
    ensures \result == ((((n)) / 111) * 111 + 111);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t res;
    
    //@ assert ((n) / 111) == n / 111;
    res = n / 111;
    
    //@ assert res == ((n) / 111);
    return res * 111 + 111;
}

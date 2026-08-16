#include <stdint.h>
/*@
    requires 1 <= n <= 1000000000;
    ensures ((\result) % 2 == 0);
    ensures ((\result) >= 2);
    ensures ((\result) == 2 * (n) || (\result) == (n));
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t res;
    //@ assert 1 <= n <= 1000000000;
    
    if (n % 2 == 0) {
        res = n;
    } else {
        res = n * 2;
    }
    
    //@ assert ((res) % 2 == 0);
    //@ assert ((res) >= 2);
    //@ assert ((res) == 2 * (n) || (res) == (n));
    
    if (res >= 2) {
        //@ assert res >= 2;
        return res;
    } else {
        //@ assert res >= 2;
        return 2 * res;
    }
}

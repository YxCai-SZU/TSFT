#include <stdint.h>
/*@
    requires (2 <= (n) && (n) <= 100);
    ensures \result == ((((n)) / 2) * ((((n)) + 1) / 2));
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t a;
    uint64_t b;
    uint64_t res;

    //@ assert (2 <= (n) && (n) <= 100);
    a = n / 2;
    b = (n + 1) / 2;
    
    //@ assert a == ((n) / 2);
    //@ assert b == (((n) + 1) / 2);
    
    //@ assert a * b <= 50 * 51;
    
    res = a * b;
    //@ assert res == ((((n)) / 2) * ((((n)) + 1) / 2));
    return res;
}

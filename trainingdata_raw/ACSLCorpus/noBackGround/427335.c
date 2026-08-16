#include <stdbool.h>
#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (x % 100) * 21 >= x;
    ensures \result == 0 ==> (x % 100) * 21 < x;
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t n;
    uint32_t a;
    uint32_t b;
    uint32_t res;

    //@ assert (1 <= (x) && (x) <= 100000);
    n = x / 100;
    a = x % 100;
    
    //@ assert a == ((x) % 100);
    //@ assert 21 * a <= 2100;
    b = 21 * a;
    
    //@ assert b == (21 * ((x) % 100));
    
    if (b >= x) {
        res = 1;
        //@ assert b >= x;
        //@ assert (x % 100) * 21 >= x;
    } else {
        res = 0;
        //@ assert b < x;
        //@ assert (x % 100) * 21 < x;
    }
    
    return res;
}

#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t ans;

    a1 = a;

    //@ assert ((a) * (a)) <= 10000;
    a2 = a * a;

    //@ assert ((a) * (a) * (a)) <= 1000;
    a3 = a * a * a;

    //@ assert ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a)))) <= 1110;
    ans = a1 + a2 + a3;

    return ans;
}

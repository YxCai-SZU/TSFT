#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    assigns \nothing;
    ensures \result == (((n) / 2) + ((n) % 2));
*/
uint32_t func(uint32_t n)
{
    //@ assert n / 2 <= 50;
    //@ assert n % 2 <= 1;
    //@ assert (n / 2) + (n % 2) <= 51;
    
    return (n / 2) + (n % 2);
}

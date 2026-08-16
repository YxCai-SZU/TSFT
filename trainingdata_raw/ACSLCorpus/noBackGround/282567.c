#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * (n) * (n));
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert n * n <= 10000;
    //@ assert n * n * n <= 1000000;
    
    return n * n * n;
}

#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b)
{
    // Variable declarations at scope top
    uint64_t i = 0;
    
    // Loop verification block
    /*@
        loop invariant 0 <= i <= 1000000;
        loop assigns i;
    */
    while (i < 1000000)
    {
        i = i + 1;
    }
    
    //@ assert a <= 100;
    //@ assert b <= 100;
    //@ assert a * b <= 10000;
    
    return a * b;
}

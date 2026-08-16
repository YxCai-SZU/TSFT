#include <stdint.h>

/*@
    requires ((n) < 0x10000);
    assigns \nothing;
    ensures \result == ((n) * (n));
    ensures \result >= 0;
*/
uint32_t is_square(uint32_t n)
{
    // Declare all variables at the top
    uint32_t ret;

    //@ assert n < 0x10000;
    //@ assert n >= 0;
    //@ assert ((n) * (n)) >= 0;
    //@ assert ((n) * (n)) < 0x100000000;
    
    ret = n * n;
    
    //@ assert ret == ((n) * (n));
    //@ assert ret >= 0;
    
    return ret;
}

/*@
    requires ((n) < 0x10000);
    assigns \nothing;
    ensures \result == ((n) * (n));
    ensures \result >= 0;
*/
uint32_t is_square2(uint32_t n)
{
    // Declare all variables at the top
    uint32_t ret;

    //@ assert n < 0x10000;
    //@ assert n >= 0;
    //@ assert ((n) * (n)) >= 0;
    //@ assert ((n) * (n)) < 0x100000000;
    
    ret = n * n;
    
    //@ assert ret == ((n) * (n));
    //@ assert ret >= 0;
    
    return ret;
}

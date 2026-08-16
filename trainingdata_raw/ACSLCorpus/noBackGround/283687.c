#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100) && (0 <= (a) && (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t a)
{
    uint32_t n_unsigned;
    uint32_t a_unsigned;
    uint32_t b_unsigned;
    int32_t b;
    
    n_unsigned = (uint32_t)n;
    a_unsigned = (uint32_t)a;
    
    //@ assert n_unsigned >= 1 && n_unsigned <= 100;
    //@ assert n_unsigned * n_unsigned <= 10000;
    
    //@ assert n_unsigned * n_unsigned >= a_unsigned;
    
    b_unsigned = n_unsigned * n_unsigned - a_unsigned;
    b = (int32_t)b_unsigned;
    
    //@ assert b == n * n - a;
    
    return b;
}

#include <stdint.h>

/*@
    requires (2 <= (k) && (k) <= 100);
    ensures \result == ((((k)) / 2) * ((((k)) + 1) / 2));
    assigns \nothing;
*/
uint32_t func(uint32_t k)
{
    uint32_t half_k;
    uint32_t half_k_plus_one;
    uint32_t result;
    
    //@ assert (2 <= (k) && (k) <= 100);
    
    half_k = k / 2;
    half_k_plus_one = (k + 1) / 2;
    
    //@ assert half_k == ((k) / 2);
    //@ assert half_k_plus_one == (((k) + 1) / 2);
    
    //@ assert 1 <= half_k && half_k <= 50;
    //@ assert 1 <= half_k_plus_one && half_k_plus_one <= 50;
    
    //@ assert half_k * half_k_plus_one <= 2500;
    
    result = half_k * half_k_plus_one;
    
    //@ assert result == ((((k)) / 2) * ((((k)) + 1) / 2));
    
    return result;
}

#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    ensures \result == (((a) * 50) / 2);
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    // Variable declarations at scope top
    uint32_t result;
    int32_t final_result;
    
    //@ assert 1 <= a <= 100;
    
    //@ assert a * 50 <= 5000;
    //@ assert a * 50 >= 50;
    
    result = a * 50;
    result = result / 2;
    final_result = (int32_t)result;
    
    //@ assert final_result == (((a) * 50) / 2);
    
    return final_result;
}

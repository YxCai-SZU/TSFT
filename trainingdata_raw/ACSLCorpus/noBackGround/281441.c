#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) * 8) >= ((b) * 10));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int scaled_a_val;
    unsigned int scaled_b_val;
    bool result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    
    scaled_a_val = a * 8;
    scaled_b_val = b * 10;
    
    //@ assert scaled_a_val >= 1 && scaled_a_val <= 800;
    //@ assert scaled_b_val >= 1 && scaled_b_val <= 1000;
    
    result = scaled_a_val >= scaled_b_val;
    
    //@ assert result == (((a) * 8) >= ((b) * 10));
    return result;
}

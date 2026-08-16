#include <stdbool.h>

/*@
    requires (1 <= (k) <= 1000 &&
        1 <= (a) <= (b) <= 1000);
    ensures \result == (((((b) / ((k)))) * (k)) >= a);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int div_val;
    unsigned int mul_val;
    bool result;

    //@ assert (1 <= (k) <= 1000 &&         1 <= (a) <= (b) <= 1000);
    
    //@ assert ((b) / (k)) <= 1000;
    div_val = b / k;
    
    //@ assert ((div_val) * (k)) <= 1000000;
    mul_val = div_val * k;
    
    result = mul_val >= a;
    
    //@ assert result == (mul_val >= a);
    return result;
}

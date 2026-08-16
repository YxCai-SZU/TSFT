#include <stdbool.h>

/*@
    requires (1 <= (k) <= 1000 &&
        1 <= (a) <= (b) <= 1000);
    ensures \result == (b / k * k >= a);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int div_result;
    unsigned int mul_result;
    bool result;

    //@ assert b / k <= 1000;
    div_result = b / k;
    
    //@ assert div_result * k <= 1000000;
    mul_result = div_result * k;
    
    result = mul_result >= a;
    return result;
}

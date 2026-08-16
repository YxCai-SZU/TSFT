#include <stdbool.h>

/*@
    requires (1 <= (k) <= 1000 && 1 <= (a) <= (b) <= 1000);
    ensures \result == (b / k * k >= a);
    assigns \nothing;
*/
bool func(unsigned long k, unsigned long a, unsigned long b)
{
    // Variable declarations at scope top
    unsigned long div_result;
    unsigned long mul_result;
    bool result;

    //@ assert (1 <= (k) <= 1000 && 1 <= (a) <= (b) <= 1000);
    
    //@ assert b / k <= 1000;
    div_result = b / k;
    
    //@ assert div_result * k <= 1000000;
    mul_result = div_result * k;
    
    result = mul_result >= a;
    return result;
}

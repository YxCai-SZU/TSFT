#include <stdbool.h>

/*@
    requires 0 <= a < 10 && 0 <= b < 10 && 0 <= c < 10;
    ensures \result == true <==> (a + b) * c <= 180;
    assigns \nothing;
*/
bool nonlinear_sum_check(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int nonlinear_sum;
    bool result;

    //@ assert (((a) + (b)) * (c)) <= 180;
    
    nonlinear_sum = (a + b) * c;
    result = nonlinear_sum <= 180;

    return result;
}

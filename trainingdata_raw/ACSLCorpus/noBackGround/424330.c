#include <stdint.h>

/*@
    requires 0 <= X <= 1000000000;
    ensures \result >= 0;
    ensures \result == 1000 * (X / 500) + 5 * ((X % 500) / 5);
*/
int64_t func(int64_t X)
{
    int64_t value;
    int64_t result;
    int64_t quotient_500;
    int64_t quotient_5;
    
    value = X;
    result = 0;
    quotient_500 = 0;
    
    //@ assert value == X;
    
    /*@
        loop invariant 0 <= value <= X;
        loop invariant 0 <= quotient_500 <= X / 500;
        loop invariant value == X - 500 * quotient_500;
        loop assigns value, quotient_500;
    */
    while (value >= 500)
    {
        value = value - 500;
        quotient_500 = quotient_500 + 1;
    }
    
    result = 1000 * quotient_500;
    quotient_5 = 0;
    
    /*@
        loop invariant 0 <= value <= X;
        loop invariant 0 <= quotient_5 <= (X - 500 * quotient_500) / 5;
        loop invariant value == X - 500 * quotient_500 - 5 * quotient_5;
        loop assigns value, quotient_5;
    */
    while (value >= 5)
    {
        value = value - 5;
        quotient_5 = quotient_5 + 1;
    }
    
    result = result + 5 * quotient_5;
    
    return result;
}

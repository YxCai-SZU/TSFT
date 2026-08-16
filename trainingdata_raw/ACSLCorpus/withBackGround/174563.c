#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 1000;
    
    logic integer division_result(integer x, integer divisor) = x / divisor;
*/

/*@
    requires is_valid_range(x);
    ensures \result >= 0;
    ensures \result * 3 <= x;
    ensures (\result - 1) * 3 < x;
*/
int func(int x)
{
    int quotient = 0;
    int remainder = x;
    int divisor = 3;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= division_result(x, divisor);
        loop invariant remainder == x - quotient * divisor;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }
    
    //@ assert quotient <= division_result(x, divisor);
    
    return quotient;
}

int main()
{
    return 0;
}

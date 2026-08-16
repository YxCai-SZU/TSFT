#include <limits.h>

/*@
    requires (1 <= (x) <= 1000);
    ensures \result == x / 3;
    assigns \nothing;
*/
int func(int x)
{
    int quotient = 0;
    int remainder = x;
    int divisor = 3;
    int is_negative = 0;
    
    if (x < 0)
    {
        remainder = -remainder;
        is_negative = 1;
    }
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant 0 <= remainder;
        loop invariant remainder == x - quotient * divisor;
        loop invariant quotient <= x / divisor;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }
    
    if (is_negative)
    {
        quotient = -quotient;
    }
    
    return quotient;
}

int main(void)
{
    return 0;
}

#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000);
    ensures \result == ((a) / 2 + ((a) % 2));
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    uint32_t quotient;
    uint32_t remainder;
    
    quotient = 0;
    remainder = a;
    
    /*@
        loop invariant 0 <= quotient <= a / 2;
        loop invariant remainder == a - 2 * quotient;
        loop invariant (1 <= (a) <= 10000);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        //@ assert remainder >= 2;
        quotient = quotient + 1;
        remainder = remainder - 2;
        //@ assert remainder == a - 2 * quotient;
    }
    
    //@ assert quotient + remainder == a / 2 + (a % 2);
    return quotient + remainder;
}

int main(void)
{
    return 0;
}

#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((2 * (n) * 314) / 100);
    assigns \nothing;
*/
int64_t func(uint64_t n)
{
    int64_t pi_approx = 314;
    int64_t circumference = 0;
    int64_t temp = 2 * (int64_t)n * pi_approx;
    int64_t quotient = 0;
    int64_t remainder = temp;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient * 100 + remainder == temp;
        loop invariant 0 <= remainder < 100 + temp;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 100)
    {
        //@ assert remainder >= 100;
        quotient += 1;
        remainder -= 100;
    }
    
    circumference = quotient;
    
    //@ assert circumference == ((2 * (n) * 314) / 100);
    return circumference;
}

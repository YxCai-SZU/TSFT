#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (3142)* (r)) / (1000));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi;
    int64_t scale;
    int64_t numerator;
    int64_t quotient;
    
    pi = 3142;
    scale = 1000;
    numerator = 2 * pi * r;
    quotient = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == (3142);
        loop invariant scale == (1000);
        loop invariant numerator >= 0;
        loop invariant numerator == 2 * (3142)* r - quotient * (1000);
        loop invariant quotient >= 0;
        loop assigns numerator, quotient;
        loop variant numerator;
    */
    while (numerator >= scale)
    {
        //@ assert numerator >= (1000);
        numerator -= scale;
        quotient += 1;
        //@ assert numerator == 2 * (3142)* r - quotient * (1000);
    }
    
    //@ assert quotient == ((2 * (3142)* (r)) / (1000));
    return quotient;
}

int main()
{
    return 0;
}

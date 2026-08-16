#include <stdint.h>

/*@
    requires (1 <= (input) && (input) <= 100000000000000000);
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t input)
{
    int64_t count;
    int64_t n;
    int64_t quotient;
    int64_t remainder;
    
    count = 0;
    n = input;
    quotient = 0;
    remainder = 0;

    /*@
        loop invariant 1 <= input && input <= 100000000000000000;
        loop invariant 0 <= quotient <= ((input) / 11);
        loop invariant n == input - quotient * 11;
        loop invariant n >= 0;
        loop assigns n, quotient;
        loop variant n;
    */
    while (n >= 11)
    {
        n = n - 11;
        quotient = quotient + 1;
        //@ assert n == input - quotient * 11;
    }
    remainder = n;

    count = quotient * 2;
    if (remainder > 6)
    {
        count = count + 1;
    }

    //@ assert count >= 0;
    return count;
}

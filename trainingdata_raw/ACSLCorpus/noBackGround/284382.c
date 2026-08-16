#include <stdint.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
*/
int64_t func(int64_t x)
{
    int64_t result;
    int64_t temp_x;
    int64_t quotient_500;
    int64_t remainder_500;
    int64_t quotient_5;
    int64_t remainder_5;
    
    result = 0;
    temp_x = x;
    quotient_500 = 0;
    remainder_500 = x;
    
    /*@
        loop invariant 0 <= quotient_500;
        loop invariant quotient_500 <= x / 500;
        loop invariant 0 <= remainder_500;
        loop invariant remainder_500 <= x;
        loop invariant remainder_500 == x - quotient_500 * 500;
        loop assigns quotient_500, remainder_500;
    */
    while (remainder_500 >= 500)
    {
        remainder_500 -= 500;
        quotient_500 += 1;
        //@ assert remainder_500 == x - quotient_500 * 500;
    }
    
    quotient_5 = 0;
    remainder_5 = remainder_500;
    
    /*@
        loop invariant 0 <= quotient_5;
        loop invariant quotient_5 <= remainder_500 / 5;
        loop invariant 0 <= remainder_5;
        loop invariant remainder_5 <= remainder_500;
        loop invariant remainder_5 == remainder_500 - quotient_5 * 5;
        loop assigns quotient_5, remainder_5;
    */
    while (remainder_5 >= 5)
    {
        remainder_5 -= 5;
        quotient_5 += 1;
        //@ assert remainder_5 == remainder_500 - quotient_5 * 5;
    }
    
    result = quotient_500 * 1000 + quotient_5 * 5;
    //@ assert result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    return result;
}

int main()
{
    return 0;
}

#include <stdint.h>

/*@
    requires (0 <= (x) && (x) <= 1000000000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t quotient_500;
    int64_t temp_x;
    int64_t quotient_5;
    int64_t temp_x2;
    int64_t result;
    
    quotient_500 = 0;
    temp_x = x;
    
    /*@
        loop invariant 0 <= quotient_500 <= x / 500;
        loop invariant temp_x == x - quotient_500 * 500;
        loop assigns quotient_500, temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        //@ assert temp_x >= 500;
        quotient_500 = quotient_500 + 1;
        temp_x = temp_x - 500;
    }
    
    quotient_5 = 0;
    temp_x2 = temp_x;
    
    /*@
        loop invariant 0 <= quotient_5 <= temp_x / 5;
        loop invariant temp_x2 == temp_x - quotient_5 * 5;
        loop assigns quotient_5, temp_x2;
        loop variant temp_x2;
    */
    while (temp_x2 >= 5)
    {
        //@ assert temp_x2 >= 5;
        quotient_5 = quotient_5 + 1;
        temp_x2 = temp_x2 - 5;
    }
    
    result = quotient_500 * 1000 + quotient_5 * 5;
    //@ assert result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    return result;
}

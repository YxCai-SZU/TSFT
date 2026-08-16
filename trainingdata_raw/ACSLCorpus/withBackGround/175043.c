#include <stdint.h>

/*@
    predicate is_in_range(integer x) = 0 <= x <= 1000000000;
    logic integer total_value(integer x) = (x / 500) * 1000 + ((x % 500) / 5) * 5;
*/

/*@
    requires is_in_range(x);
    ensures \result == total_value(x);
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t res = 0;
    int64_t temp_x = x;
    int64_t quotient_500 = 0;
    int64_t remainder_500 = 0;
    int64_t quotient_5 = 0;
    int64_t remainder_5 = 0;
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant quotient_500 * 500 == x - temp_x;
        loop invariant 0 <= quotient_500;
        loop assigns temp_x, quotient_500;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        quotient_500 += 1;
        temp_x -= 500;
    }
    remainder_500 = temp_x;
    
    res += quotient_500 * 1000;
    
    /*@
        loop invariant 0 <= remainder_500 <= x % 500;
        loop invariant quotient_5 * 5 == (x % 500) - remainder_500;
        loop invariant 0 <= quotient_5;
        loop assigns remainder_500, quotient_5;
        loop variant remainder_500;
    */
    while (remainder_500 >= 5)
    {
        quotient_5 += 1;
        remainder_500 -= 5;
    }
    remainder_5 = remainder_500;
    
    res += quotient_5 * 5;
    
    //@ assert res == total_value(x);
    
    return res;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}

#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer calculate_result(integer r) = 
        2 * 31415926535 * r / 10000000000;
*/

/*@
    requires valid_range(r);
    ensures \result == calculate_result(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t circumference;
    int64_t temp;
    int64_t divisor;
    
    pi = 31415926535;
    circumference = 0;
    temp = 2 * pi * r;
    divisor = 10000000000;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 31415926535;
        loop invariant divisor == 10000000000;
        loop invariant temp >= 0;
        loop invariant circumference * divisor + temp == 2 * pi * r;
        loop assigns temp, circumference;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        //@ assert temp >= divisor;
        temp -= divisor;
        circumference += 1;
    }
    
    //@ assert circumference == calculate_result(r);
    return circumference;
}

int main()
{
    return 0;
}

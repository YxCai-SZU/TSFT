#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (r) * (314159)) / (100000));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t circumference;
    int64_t divisor;
    int64_t result;
    int64_t temp;
    
    pi_approx = 314159;
    circumference = r * 2 * pi_approx;
    divisor = 100000;
    result = 0;
    temp = circumference;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant (314159)== 314159;
        loop invariant circumference == r * 2 * (314159);
        loop invariant (100000)== 100000;
        loop invariant result * (100000)+ temp == circumference;
        loop invariant 0 <= result;
        loop invariant result <= ((2 * (r) * (314159)) / (100000));
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        result += 1;
    }
    
    //@ assert result * (100000)+ temp == circumference;
    //@ assert result == ((2 * (r) * (314159)) / (100000));
    
    return result;
}

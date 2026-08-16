#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    logic integer scaled_pi = 3141592;
    logic integer divisor_val = 1000000;
    logic integer target_value(integer r) = 2 * scaled_pi * r / divisor_val;
*/

/*@
    requires valid_range(r);
    ensures \result == target_value(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi;
    int64_t result;
    int64_t temp;
    int64_t divisor;
    
    pi = 3141592;
    result = 0;
    temp = 2 * pi * r;
    divisor = 1000000;
    
    /*@
        loop invariant valid_range(r);
        loop invariant 2 * 3141592 * r == temp + (result * divisor);
        loop invariant result * 1000000 + temp == 2 * 3141592 * r;
        loop invariant 0 <= temp <= 2 * pi * r;
        loop invariant 0 <= result <= (2 * pi * r) / divisor;
        loop assigns temp, result;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        result += 1;
    }
    
    //@ assert 2 * 3141592 * r == temp + (result * divisor);
    //@ assert result * 1000000 + temp == 2 * 3141592 * r;
    
    return result;
}

int main(void)
{
    return 0;
}

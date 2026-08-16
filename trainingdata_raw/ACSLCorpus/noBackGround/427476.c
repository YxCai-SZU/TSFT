#include <stdint.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * 3141592 * r / 1000000;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi = 3141592;
    int64_t result = 0;
    int64_t temp = 2 * pi * r;
    int64_t divisor = 1000000;
    
    //@ assert (1 <= (r) <= 100);
    //@ assert (0 <= (temp) <= 2 * 3141592 * 100);
    //@ assert (0 <= (result) * 1000000 <= 2 * 3141592 * 100);
    
    /*@
        loop invariant (1 <= (r) <= 100);
        loop invariant (0 <= (temp) <= 2 * 3141592 * 100);
        loop invariant (0 <= (result) * 1000000 <= 2 * 3141592 * 100);
        loop invariant result * 1000000 + temp == 2 * pi * r;
        loop assigns temp, result;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        result += 1;
        
        //@ assert (0 <= (temp) <= 2 * 3141592 * 100);
        //@ assert (0 <= (result) * 1000000 <= 2 * 3141592 * 100);
    }
    
    //@ assert result * 1000000 <= 2 * pi * r;
    //@ assert result * 1000000 + temp == 2 * pi * r;
    //@ assert temp < divisor;
    
    return result;
}

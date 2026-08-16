#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (r) * 3141592) / 1000000);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi = 3141592;
    int64_t result = 0;
    int64_t temp = 2 * r * pi;
    int64_t count = 0;
    
    //@ assert temp == (2 * (r) * 3141592 - (0) * 1000000);
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant 0 <= temp <= 2 * 100 * 3141592;
        loop invariant temp == (2 * (r) * 3141592 - (count) * 1000000);
        loop invariant count * 1000000 <= 2 * r * pi;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 1000000)
    {
        //@ assert temp >= 1000000;
        temp -= 1000000;
        count += 1;
        //@ assert temp == (2 * (r) * 3141592 - (count) * 1000000);
    }
    
    result = count;
    
    //@ assert result * 1000000 + temp == 2 * r * pi;
    //@ assert temp < 1000000;
    //@ assert result == ((2 * (r) * 3141592) / 1000000);
    
    return result;
}

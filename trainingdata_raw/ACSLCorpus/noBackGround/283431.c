#include <stdint.h>

/*@ requires (1 <= (r) <= 100);
    ensures \result == ((2 * 31415 * (r)) / 10000);
*/
int32_t func(int32_t r)
{
    int32_t pi_approx;
    int32_t circumference;
    int32_t temp;
    int32_t count;
    
    pi_approx = 31415;
    circumference = 0;
    temp = 2 * pi_approx * r;
    count = 0;
    
    /*@
        loop invariant temp >= 0;
        loop invariant temp == 2 * 31415 * r - 10000 * count;
        loop assigns temp, count;
    */
    while (temp >= 10000)
    {
        temp -= 10000;
        count += 1;
    }
    
    circumference = count;
    
    //@ assert circumference * 10000 + temp == 2 * pi_approx * r;
    
    return circumference;
}

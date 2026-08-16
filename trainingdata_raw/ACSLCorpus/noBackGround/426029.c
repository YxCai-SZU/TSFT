#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((2 * (r) * 31416) / 10000);
    assigns \nothing;
*/
int func(int r)
{
    int pi_approx;
    int scale;
    int circumference;
    int temp;
    int count;
    
    pi_approx = 31416;
    scale = 10000;
    circumference = 0;
    temp = 2 * r * pi_approx;
    count = 0;
    
    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant pi_approx == 31416;
        loop invariant scale == 10000;
        loop invariant temp >= 0;
        loop invariant ((temp) == 2 * (r) * 31416 - (count) * 10000);
        loop invariant count >= 0;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= scale)
    {
        //@ assert temp >= scale;
        temp -= scale;
        count += 1;
    }
    
    circumference = count;
    
    //@ assert circumference == ((2 * (r) * 31416) / 10000);
    return circumference;
}

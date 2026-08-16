#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (r) * (31416)) / (10000));
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    // Variable declarations at scope top
    int32_t pi_approx;
    int32_t scale;
    int32_t ans;
    int32_t temp;
    
    pi_approx = 31416;
    scale = 10000;
    ans = 0;
    temp = 2 * r * pi_approx;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant (31416)== 31416;
        loop invariant (10000)== 10000;
        loop invariant ans >= 0;
        loop invariant temp >= 0;
        loop invariant temp == 2 * r * (31416)- ans * (10000);
        loop assigns ans, temp;
        loop variant temp;
    */
    while (temp >= scale)
    {
        //@ assert temp >= (10000);
        ans += 1;
        temp -= scale;
    }
    
    //@ assert ans == ((2 * (r) * (31416)) / (10000));
    return ans;
}

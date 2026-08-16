#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == 2 * r * 314 / 100;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi_approx;
    int64_t ans;
    int64_t result;
    int64_t temp_ans;
    int64_t divisor;
    int64_t count;
    
    pi_approx = 314;
    ans = r * 2 * pi_approx;
    
    result = 0;
    temp_ans = ans;
    divisor = 100;
    count = 0;
    
    //@ assert (1 <= (r) <= 100);
    //@ assert pi_approx == 314;
    //@ assert ans == ((r) * 2 * (pi_approx));
    //@ assert divisor == 100;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 314;
        loop invariant ans == ((r) * 2 * (pi_approx));
        loop invariant divisor == 100;
        loop invariant temp_ans >= 0;
        loop invariant ans == temp_ans + divisor * count;
        loop invariant count >= 0;
        loop assigns temp_ans, count;
        loop variant temp_ans;
    */
    while (temp_ans >= divisor)
    {
        //@ assert temp_ans >= divisor;
        temp_ans -= divisor;
        count += 1;
        //@ assert ans == temp_ans + divisor * count;
    }
    
    result = count;
    //@ assert result == 2 * r * 314 / 100;
    return result;
}

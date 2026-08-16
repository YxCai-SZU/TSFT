#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == 2 * 314159 * r / 100000;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi_approx;
    int64_t circumference;
    int64_t divisor;
    int64_t ans;
    int64_t temp;
    
    pi_approx = 314159;
    //@ assert pi_approx == (314159);
    
    circumference = 2 * pi_approx * r;
    //@ assert circumference == (2 * (314159)* (r));
    
    ans = 0;
    temp = circumference;
    divisor = 100000;
    //@ assert divisor == (100000);
    
    //@ assert ((1 <= ((r)) <= 100) &&         (pi_approx) == (314159)&&         (circumference) == (2 * (314159)* ((r))) &&         (divisor) == (100000)&&         (circumference) == ((temp) + (ans) * (divisor)) &&         (ans) >= 0 &&         (temp) >= 0);
    
    /*@
        loop invariant ((1 <= ((r)) <= 100) &&
        (pi_approx) == (314159)&&
        (circumference) == (2 * (314159)* ((r))) &&
        (divisor) == (100000)&&
        (circumference) == ((temp) + (ans) * (divisor)) &&
        (ans) >= 0 &&
        (temp) >= 0);
        loop assigns ans, temp;
        loop variant temp;
    */
    while (temp >= divisor) {
        //@ assert temp >= divisor;
        temp -= divisor;
        ans += 1;
        //@ assert ((1 <= ((r)) <= 100) &&         (pi_approx) == (314159)&&         (circumference) == (2 * (314159)* ((r))) &&         (divisor) == (100000)&&         (circumference) == ((temp) + (ans) * (divisor)) &&         (ans) >= 0 &&         (temp) >= 0);
    }
    
    //@ assert temp < divisor;
    //@ assert ans * divisor + temp == 2 * pi_approx * r;
    
    return ans;
}

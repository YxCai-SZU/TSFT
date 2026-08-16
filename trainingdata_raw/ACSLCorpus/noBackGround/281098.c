#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (314)* (r)) / 100);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi_approx;
    int64_t circumference;
    int64_t result;
    int64_t temp;
    
    pi_approx = 314;
    circumference = 2 * pi_approx * r;
    
    result = 0;
    temp = circumference;
    
    /*@
        loop invariant result * 100 + temp == circumference;
        loop invariant temp >= 0;
        loop assigns result, temp;
    */
    while (temp >= 100)
    {
        temp -= 100;
        result += 1;
    }
    
    //@ assert result * 100 + temp == circumference;
    
    return result;
}

int main()
{
    return 0;
}

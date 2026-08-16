#include <stdint.h>

/*@
    predicate is_valid_range(integer r) = 1 <= r <= 100;
    logic integer scaled_pi = 314159;
    logic integer divisor_val = 100000;
    logic integer initial_temp(integer r) = 2 * scaled_pi * r;
    logic integer expected_result(integer r) = 2 * 314159 * r / 100000;
*/

/*@
    requires is_valid_range(r);
    ensures \result == expected_result(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi;
    int64_t ans;
    int64_t temp;
    int64_t divisor;
    
    pi = 314159;
    ans = 0;
    temp = 2 * pi * r;
    divisor = 100000;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314159;
        loop invariant divisor == 100000;
        loop invariant temp >= 0;
        loop invariant ans == (2 * pi * r - temp) / divisor;
        loop invariant ans >= 0;
        loop invariant temp + ans * divisor == 2 * pi * r;
        loop assigns temp, ans;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        ans += 1;
    }
    
    //@ assert ans == (2 * pi * r - temp) / divisor;
    //@ assert 2 * 314159 * r == 2 * pi * r;
    //@ assert 2 * 314159 * r / 100000 == (2 * pi * r - temp) / divisor;
    
    return ans;
}

int main()
{
    return 0;
}

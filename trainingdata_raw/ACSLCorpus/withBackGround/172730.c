#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer calculate_result(integer r) = 
        2 * 31415 * r / 10000;
*/

/*@
    requires valid_range(r);
    ensures \result == calculate_result(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t ans;
    int64_t temp;
    int64_t divisor;
    
    pi = 31415;
    ans = 0;
    temp = 2 * pi * r;
    divisor = 10000;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 31415;
        loop invariant divisor == 10000;
        loop invariant ans >= 0;
        loop invariant temp >= 0;
        loop invariant temp == 2 * pi * r - ans * divisor;
        loop invariant 2 * pi * r <= 2 * 31415 * 100;
        loop invariant ans * 10000 <= 2 * 31415 * 100;
        loop assigns temp, ans;
    */
    while (temp >= divisor)
    {
        //@ assert temp >= divisor;
        temp -= divisor;
        ans += 1;
    }
    
    //@ assert ans == calculate_result(r);
    return ans;
}

int main()
{
    return 0;
}

#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    logic integer scaled_product(integer r) = 2 * 314159 * r;
    logic integer expected_result(integer r) = scaled_product(r) / 100000;
*/

/*@
    requires valid_range(r);
    ensures \result == expected_result(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t scale;
    int64_t scaled_value;
    int64_t ans;
    
    pi = 314159;
    scale = 100000;
    scaled_value = 2 * pi * r;
    ans = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314159;
        loop invariant scale == 100000;
        loop invariant scaled_value >= 0;
        loop invariant ans >= 0;
        loop invariant scaled_value == 2 * pi * r - ans * scale;
        loop assigns scaled_value, ans;
        loop variant scaled_value;
    */
    while (scaled_value >= scale)
    {
        scaled_value -= scale;
        ans += 1;
    }
    
    //@ assert scaled_value == 2 * pi * r - ans * scale;
    //@ assert scaled_value < scale;
    //@ assert ans * scale + scaled_value == 2 * pi * r;
    //@ assert ans * scale + scaled_value == 2 * 314159 * r;
    //@ assert ans == (2 * 314159 * r - scaled_value) / 100000;
    
    return ans;
}

int main()
{
    return 0;
}

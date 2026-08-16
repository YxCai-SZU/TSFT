#include <stdint.h>

/*@
    predicate is_valid_range(integer r) = 1 <= r <= 100;
    
    logic integer fixed_pi = 314159;
    logic integer fixed_two = 2;
    logic integer fixed_scale = 100000;
    
    logic integer expected_result(integer r) = 
        (2 * r * fixed_pi) / fixed_scale;
*/

/*@
    requires is_valid_range(r);
    ensures \result == expected_result(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t two;
    int64_t scale;
    int64_t result;
    int64_t temp_r;
    int64_t count;
    
    pi = 314159;
    two = 2;
    scale = 100000;
    result = 0;
    temp_r = r * two * pi;
    count = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314159;
        loop invariant two == 2;
        loop invariant scale == 100000;
        loop invariant temp_r >= 0;
        loop invariant temp_r <= r * two * pi;
        loop invariant count * scale + temp_r == r * two * pi;
        loop invariant count >= 0;
        loop invariant count <= (r * two * pi) / scale;
        loop assigns temp_r, count;
        loop variant temp_r;
    */
    while (temp_r >= scale)
    {
        temp_r -= scale;
        count += 1;
    }
    result = count;
    
    //@ assert r * two * pi <= 100 * 2 * 314159;
    //@ assert 0 <= r * two * pi;
    
    return result;
}

int main(void)
{
    return 0;
}

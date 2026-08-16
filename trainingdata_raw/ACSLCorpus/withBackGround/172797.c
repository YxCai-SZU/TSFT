#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer scaled_pi(integer r) = 2 * r * 3142;
    
    logic integer expected_result(integer r) = 2 * r * 3142 / 1000;
*/

/*@
    requires valid_range(r);
    ensures \result == expected_result(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi;
    int64_t scale;
    int64_t result;
    int64_t temp;
    
    pi = 3142;
    scale = 1000;
    result = 0;
    temp = 2 * r * pi;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 3142;
        loop invariant scale == 1000;
        loop invariant temp >= 0;
        loop invariant temp == 2 * r * pi - result * scale;
        loop invariant result * scale + temp == 2 * r * pi;
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= scale)
    {
        //@ assert temp >= scale;
        result += 1;
        temp -= scale;
    }
    
    //@ assert result == expected_result(r);
    return result;
}

int main()
{
    return 0;
}

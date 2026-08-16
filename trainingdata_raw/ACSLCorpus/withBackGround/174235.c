#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer expected_result(integer r) = (2 * r * 3142) / 1000;
    
    lemma result_calculation: 
        \forall integer r; valid_range(r) ==> expected_result(r) == (2 * r * 3142) / 1000;
*/

/*@
    requires valid_range(r);
    ensures \result == expected_result(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t two;
    int64_t scale;
    int64_t result;
    int64_t temp;
    
    pi_approx = 3142;
    two = 2;
    scale = 1000;
    result = 0;
    temp = two * r * pi_approx;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 3142;
        loop invariant two == 2;
        loop invariant scale == 1000;
        loop invariant temp >= 0;
        loop invariant result * scale + temp == two * r * pi_approx;
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= scale)
    {
        temp -= scale;
        result += 1;
    }
    
    //@ assert result * scale + temp == two * r * pi_approx;
    //@ assert temp < scale;
    //@ assert temp >= 0;
    //@ assert result == expected_result(r);
    
    return result;
}

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer calculate_circumference(integer r) = r * 2 * 314;
    
    logic integer expected_result(integer r) = 2 * r * 314 / 100;
    
    lemma division_property: 
        \forall integer r, integer temp, integer result; 
        valid_range(r) && calculate_circumference(r) == (temp + result * 100) ==> 
        result * 100 + temp == calculate_circumference(r);
*/

#include <stdint.h>

/*@
    requires valid_range(r);
    ensures \result == expected_result(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi_approx;
    int64_t circumference;
    int64_t result;
    int64_t temp;
    int64_t divisor;
    
    pi_approx = 314;
    circumference = r * 2 * pi_approx;
    result = 0;
    temp = circumference;
    divisor = 100;
    
    /*@
        loop invariant valid_range(r);
        loop invariant pi_approx == 314;
        loop invariant circumference == calculate_circumference(r);
        loop invariant divisor == 100;
        loop invariant circumference == (temp + result * divisor);
        loop invariant result * 100 + temp == calculate_circumference(r);
        loop invariant 0 <= result * 100 + temp <= 2 * 100 * 314;
        loop invariant 0 <= temp < 100 + 2 * 100 * 314;
        loop assigns temp, result;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        result += 1;
    }
    
    //@ assert result * 100 + temp == calculate_circumference(r);
    //@ assert temp < 100;
    
    return result;
}

int main()
{
    return 0;
}

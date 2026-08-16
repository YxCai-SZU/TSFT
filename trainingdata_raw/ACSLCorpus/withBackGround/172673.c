#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer calculate_ans(integer r) = 2 * 314159 * r;
    
    logic integer expected_result(integer r) = 2 * 314159 * r / 100000;
*/

/*@
    requires valid_range(r);
    ensures \result == expected_result(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t ans;
    int64_t quotient;
    int64_t remainder;
    int64_t divisor;
    
    pi = 314159;
    ans = 2 * pi * r;
    quotient = 0;
    remainder = ans;
    divisor = 100000;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314159;
        loop invariant ans == 2 * pi * r;
        loop invariant quotient * divisor + remainder == ans;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }
    
    //@ assert quotient * divisor + remainder == ans;
    //@ assert quotient == ans / divisor;
    //@ assert remainder == ans % divisor;
    
    return quotient;
}

/*@
    lemma quotient_calculation:
        \forall integer r, ans, divisor, quotient, remainder;
        1 <= r <= 100 && ans == 2 * 314159 * r && divisor == 100000 &&
        quotient >= 0 && remainder >= 0 && quotient * divisor + remainder == ans &&
        remainder < divisor ==> quotient == ans / divisor;
*/

int main()
{
    return 0;
}

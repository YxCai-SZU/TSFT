#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer calculate_expected(integer r) = (2 * r * 314) / 100;
    
    lemma division_property:
        \forall integer r;
        valid_range(r) ==> calculate_expected(r) == (2 * r * 314) / 100;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == (2 * r * 314) / 100;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi = 314;
    int64_t ans = 0;
    int64_t temp = 2 * r * pi;
    int64_t quotient = 0;
    int64_t remainder = 0;
    int64_t divisor = 100;
    
    //@ assert valid_range(r);
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant 0 <= remainder;
        loop invariant temp == 2 * r * pi - quotient * divisor - remainder;
        loop invariant 0 <= temp;
        loop assigns temp, quotient;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        quotient += 1;
    }
    remainder = temp;
    ans = quotient;
    
    //@ assert ans == (2 * r * 314) / 100;
    return ans;
}

int main(void)
{
    return 0;
}

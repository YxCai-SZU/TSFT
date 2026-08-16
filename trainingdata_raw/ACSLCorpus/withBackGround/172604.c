#include <limits.h>

/*@
    predicate is_valid_range(integer n) = 1 <= n <= 1000;
    
    logic integer division_result(integer n) = n / 3;
*/

/*@
    requires is_valid_range(n);
    ensures \result >= 0;
    ensures \result == division_result(n);
    assigns \nothing;
*/
int func(int n)
{
    int quotient;
    int remainder;
    int divisor;
    
    quotient = 0;
    remainder = n;
    divisor = 3;
    
    /*@
        loop invariant 0 <= quotient <= division_result(n);
        loop invariant remainder == n - quotient * divisor;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }
    
    return quotient;
}

/*@
    lemma division_non_negative: 
        \forall integer n; is_valid_range(n) ==> division_result(n) >= 0;
*/

int main()
{
    return 0;
}

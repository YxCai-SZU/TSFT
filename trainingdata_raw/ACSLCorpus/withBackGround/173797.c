/*@
    predicate is_valid_range(integer n) = 10 <= n && n <= 99;
    
    logic integer manual_div(integer n, integer divisor) = n / divisor;
    logic integer manual_mod(integer n, integer divisor) = n % divisor;
    
    lemma div_mod_relation:
        \forall integer n, divisor; divisor > 0 ==> 
            n == manual_div(n, divisor) * divisor + manual_mod(n, divisor);
*/

#include <stdbool.h>

/*@
    requires is_valid_range(n);
    ensures \result <==> (n / 10 == 9) || (n % 10 == 9);
    assigns \nothing;
*/
bool func(int n)
{
    // Variable declarations at top of scope
    int quotient = 0;
    int remainder = n;
    int divisor = 10;
    
    /*@
        loop invariant 10 <= n <= 99;
        loop invariant 0 <= quotient <= n / divisor;
        loop invariant remainder == n - quotient * divisor;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        remainder -= divisor;
        quotient += 1;
    }
    
    return (quotient == 9) || (remainder == 9);
}

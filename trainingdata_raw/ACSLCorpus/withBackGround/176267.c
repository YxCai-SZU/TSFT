/*@
    predicate is_valid_range(integer n) = 1 <= n && n <= 99999;
    
    logic integer tens_digit(integer n) = (n / 10) % 10;
    logic integer ones_digit(integer n) = n % 10;
    
    lemma division_bounds: \forall integer n; is_valid_range(n) ==> 
        (n / 10) <= 9999 && (n % 10) <= 9;
*/

#include <stdbool.h>

/*@
    requires is_valid_range(n);
    ensures \result == (tens_digit(n) == ones_digit(n));
    assigns \nothing;
*/
bool func(unsigned int n)
{
    // Variable declarations at scope top
    unsigned int tens;
    unsigned int ones;
    bool result;
    
    //@ assert is_valid_range(n);
    
    tens = (n / 10) % 10;
    ones = n % 10;
    result = (tens == ones);
    
    //@ assert result == (tens_digit(n) == ones_digit(n));
    return result;
}

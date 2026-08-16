#include <stdbool.h>

/*@
    predicate is_digit_nine(integer n) = n % 10 == 9;
    predicate is_tens_digit_nine(integer n) = (n / 10) % 10 == 9;
    predicate result_condition(integer n, bool r) = 
        r == (n % 10 == 9 || (n / 10) % 10 == 9);
*/

/*@
    requires 10 <= n <= 99;
    ensures \result == (n % 10 == 9 || (n / 10) % 10 == 9);
    assigns \nothing;
*/
bool func(unsigned long n)
{
    unsigned int n_unsigned;
    bool result;
    
    n_unsigned = (unsigned int)n;
    //@ assert n_unsigned / 10 <= 9;
    
    result = (n_unsigned % 10 == 9) || ((n_unsigned / 10) % 10 == 9);
    //@ assert result == (n % 10 == 9 || (n / 10) % 10 == 9);
    
    return result;
}

#include <stdbool.h>

/*@
    predicate is_two_digit(integer a) = 10 <= a && a <= 99;
    
    logic integer tens_digit(integer a) = a / 10;
    logic integer ones_digit(integer a) = a % 10;
    
    predicate has_nine(integer a) = 
        tens_digit(a) == 9 || ones_digit(a) == 9;
*/

/*@
    requires is_two_digit(a);
    ensures \result == (tens_digit(a) == 9 || ones_digit(a) == 9);
    assigns \nothing;
*/
bool func(int a)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert is_two_digit(a);
    
    result = (a / 10 == 9) || (a % 10 == 9);
    
    //@ assert result == (tens_digit(a) == 9 || ones_digit(a) == 9);
    return result;
}

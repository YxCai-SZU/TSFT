#include <stdint.h>

/*@
    predicate is_single_digit(integer n) = 1 <= n && n <= 9;
    
    logic integer square(integer n) = n * n;
    
    lemma square_bounds:
        \forall integer n; is_single_digit(n) ==> 
            square(n) >= 1 && square(n) <= 81;
*/

/*@
    requires is_single_digit(n);
    ensures \result == square(n);
    ensures \result >= 1;
    ensures \result <= 81;
    assigns \nothing;
*/
uint32_t is_square(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert is_single_digit(n);
    
    //@ assert square(n) >= 1;
    //@ assert square(n) <= 81;
    
    result = n * n;
    
    //@ assert result == square(n);
    //@ assert result >= 1;
    //@ assert result <= 81;
    
    return result;
}

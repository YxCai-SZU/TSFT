#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 10000;
    predicate b_in_range(integer b) = 1 <= b <= 10000;
    predicate product_in_range(integer a, integer b) = a * b <= 10000 * 10000;
    predicate is_odd_result(integer a, integer b, bool result) = 
        result == (a * b % 2 != 0);
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures is_odd_result(a, b, \result);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int product;
    bool is_odd;
    
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    //@ assert a * b <= 10000 * 10000;
    
    product = a * b;
    //@ assert product == a * b;
    
    is_odd = (product % 2) != 0;
    //@ assert is_odd == (a * b % 2 != 0);
    
    return is_odd;
}

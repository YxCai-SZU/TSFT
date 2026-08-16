#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 3;
    predicate b_in_range(integer b) = 1 <= b <= 3;
    logic integer product(integer a, integer b) = a * b;
    logic integer mod_result(integer a, integer b) = product(a, b) % 2;
    predicate is_odd_product(integer a, integer b) = mod_result(a, b) != 0;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == (mod_result(a, b) != 0);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b)
{
    // Variable declarations at scope top
    unsigned long ans;
    bool result;

    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert product(a, b) <= 9;
    
    ans = (a * b) % 2;
    //@ assert ans == mod_result(a, b);
    
    result = (ans != 0);
    //@ assert result == (mod_result(a, b) != 0);
    
    return result;
}

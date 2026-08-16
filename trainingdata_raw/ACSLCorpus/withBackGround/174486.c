#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer safe_div(integer a) = (a - 1) / 3;

    lemma div_bound: \forall integer a; 1 <= a <= 100 ==> 0 <= safe_div(a) <= 33;

    lemma comparison_safe: \forall integer a, b; 
        valid_range(a, b) ==> 
        (safe_div(a) >= b - 1) ==> (safe_div(a) >= b - 1);
*/

/*@
    requires valid_range(a, b);
    ensures \result == (safe_div(a) >= b - 1);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    //@ assert a > 0 && a <= 100;
    //@ assert b > 0 && b <= 100;
    
    //@ assert 0 <= (a - 1) / 3 <= 33;
    
    //@ assert (a - 1) / 3 >= b - 1 ==> (a - 1) / 3 >= b - 1;
    
    return (a - 1) / 3 >= b - 1;
}

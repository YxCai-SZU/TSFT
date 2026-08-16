#include <stdbool.h>

/*@
    predicate valid_params(integer k, integer a, integer b) =
        1 <= k && k <= 1000 &&
        1 <= a && a <= 1000 &&
        1 <= b && b <= 1000;

    logic integer safe_div(integer x, integer y) =
        x / y;

    lemma div_bounds_a:
        \forall integer k, integer a;
        valid_params(k, a, a) ==> safe_div(a, k) <= 1000;

    lemma div_bounds_b:
        \forall integer k, integer b;
        valid_params(k, b, b) ==> safe_div(b, k) <= 1000;
*/

/*@
    requires valid_params(k, a, b);
    ensures \result == (safe_div(b, k) <= safe_div(a, k));
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int b_div_k;
    unsigned int a_div_k;

    //@ assert valid_params(k, a, b);
    
    //@ assert safe_div(b, k) <= 1000;
    b_div_k = b / k;
    
    //@ assert safe_div(a, k) <= 1000;
    a_div_k = a / k;
    
    result = b_div_k <= a_div_k;
    //@ assert result == (safe_div(b, k) <= safe_div(a, k));
    
    return result;
}

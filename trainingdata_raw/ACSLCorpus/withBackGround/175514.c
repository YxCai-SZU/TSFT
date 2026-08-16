#include <stdbool.h>

/*@
    predicate is_valid_range(integer k, integer a, integer b) =
        1 <= k <= 1000 && 1 <= a <= b <= 1000;

    logic integer division_result(integer b, integer k) = b / k;

    lemma division_bound: \forall integer k, b; 
        is_valid_range(k, 1, b) ==> division_result(b, k) * k <= b;
*/

/*@
    requires is_valid_range(k, a, b);
    ensures \result == true <==> (b / k) * k >= a;
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int a, unsigned int b)
{
    unsigned int div;
    bool result;

    //@ assert is_valid_range(k, a, b);
    div = b / k;
    
    //@ assert div * k <= b;
    result = (div * k >= a);
    
    //@ assert result == true <==> (b / k) * k >= a;
    return result;
}

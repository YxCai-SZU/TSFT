#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 0 <= x <= 1;
    
    logic integer complement(integer x) = 1 - x;
    
    lemma complement_in_range: 
        \forall integer x; is_valid_range(x) ==> 0 <= complement(x) <= 1;
*/

/*@
    requires is_valid_range(x);
    ensures \result == complement(x);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    
    //@ assert is_valid_range(x);
    result = 1 - x;
    
    //@ assert result == complement(x);
    //@ assert 0 <= result && result <= 1;
    
    return result;
}

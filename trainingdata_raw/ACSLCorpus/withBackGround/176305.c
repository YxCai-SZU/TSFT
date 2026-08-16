#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= b <= a <= 20 && 1 <= c <= 20;
    
    logic integer min_val(integer a, integer b, integer c) =
        (a - b) < c ? (a - b) : c;
    
    lemma result_property:
        \forall integer a, b, c, result;
        valid_range(a, b, c) && result == c - min_val(a, b, c) ==>
        (result >= 0 && result <= c &&
         (result == c - (a - b) || result == 0));
*/

/*@
    requires valid_range(a, b, c);
    ensures \result >= 0 && \result <= c;
    ensures \result == c - (a - b) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int min_val;
    int result;
    
    //@ assert valid_range(a, b, c);
    
    if (a - b < c) {
        min_val = a - b;
    } else {
        min_val = c;
    }
    
    //@ assert min_val == min_val(a, b, c);
    
    result = c - min_val;
    
    //@ assert result == c - min_val(a, b, c);
    //@ assert result >= 0;
    //@ assert result <= c;
    //@ assert (a - b < c && result == c - (a - b)) || (a - b >= c && result == 0);
    
    return result;
}

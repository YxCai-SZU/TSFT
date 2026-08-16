#include <stdbool.h>

/*@
    predicate is_valid_x(integer x) = 0 <= x <= 1;

    logic integer func_spec(integer x) =
        x == 0 ? 1 : 0;

    lemma func_lemma:
        \forall integer x;
        is_valid_x(x) ==> func_spec(x) == 1 - x;
*/

/*@
    requires is_valid_x(x);
    ensures \result == func_spec(x);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    
    //@ assert x == 0 || x == 1;
    //@ assert x * x == 0 || x * x == 1;
    //@ assert 1 - x == 1 || 1 - x == 0;
    
    result = 1 - x;
    return result;
}

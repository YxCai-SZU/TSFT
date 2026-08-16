#include <stdbool.h>

/*@
    predicate is_valid_input(integer x) = 0 <= x <= 1;

    logic integer func_result(integer x) =
        x == 0 ? 1 : 0;

    lemma func_correctness:
        \forall integer x;
        is_valid_input(x) ==>
        (x == 0 ==> func_result(x) == 1) &&
        (x == 1 ==> func_result(x) == 0);
*/

/*@
    requires is_valid_input(x);
    ensures (x == 0 ==> \result == 1) && (x == 1 ==> \result == 0);
    assigns \nothing;
*/
int func(int x)
{
    int result;

    //@ assert is_valid_input(x);
    
    if (x == 0) {
        result = 1;
    } else {
        result = 0;
    }

    //@ assert (x == 0 ==> result == 1) && (x == 1 ==> result == 0);
    
    return result;
}

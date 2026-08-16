#include <stdbool.h>

/*@
    predicate is_valid_input(integer x) = 0 <= x <= 1;

    logic integer func_spec(integer x) = 1 - x;

    lemma func_correctness:
        \forall integer x;
            is_valid_input(x) ==>
            (x == 0 ==> func_spec(x) == 1) &&
            (x == 1 ==> func_spec(x) == 0);
*/

/*@
    requires is_valid_input(x);
    ensures \result == func_spec(x);
    ensures (x == 0 ==> \result == 1);
    ensures (x == 1 ==> \result == 0);
*/
int func(int x)
{
    int result;
    //@ assert is_valid_input(x);
    result = 1 - x;
    //@ assert result == func_spec(x);
    return result;
}

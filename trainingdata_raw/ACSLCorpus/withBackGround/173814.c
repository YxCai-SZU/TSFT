#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = 0 <= x <= 1;

    logic integer func_result(integer x) =
        x == 0 ? 1 : 0;

    lemma func_correctness:
        \forall integer x;
            is_valid_input(x) ==> func_result(x) == (x == 0 ? 1 : 0);
*/

/*@
    requires is_valid_input(x);
    ensures \result == func_result(x);
    ensures (x == 0 ==> \result == 1) && (x == 1 ==> \result == 0);
*/
uint32_t func(uint32_t x)
{
    uint32_t result;

    //@ assert is_valid_input(x);

    if (x == 0)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    //@ assert (x == 0 ==> result == 1) && (x == 1 ==> result == 0);

    return result;
}

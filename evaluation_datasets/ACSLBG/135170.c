#include <stdint.h>

/*@
    predicate is_valid_X(integer X) = 0 <= X <= 1;
    logic integer func_result(integer X) = 1 - X;
    lemma result_range: \forall integer X; is_valid_X(X) ==> 0 <= func_result(X) <= 1;
    lemma zero_case: \forall integer X; is_valid_X(X) && X == 0 ==> func_result(X) == 1;
    lemma one_case: \forall integer X; is_valid_X(X) && X == 1 ==> func_result(X) == 0;
*/


int32_t func(int32_t X)
{
    //@ assert is_valid_X(X);
    int32_t result;
    result = 1 - X;
    //@ assert result == func_result(X);
    //@ assert (X == 0 ==> result == 1) && (X == 1 ==> result == 0);
    return result;
}

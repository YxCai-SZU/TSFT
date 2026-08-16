#include <stdint.h>

/*@
    predicate is_valid_x(integer x) = 0 <= x <= 1;

    logic integer func_spec(integer x) = 1 - x;

    lemma func_result_range: \forall integer x; is_valid_x(x) ==> (func_spec(x) == 0 || func_spec(x) == 1);
*/

/*@
    requires is_valid_x(x);
    ensures \result == func_spec(x);
    ensures \result == 0 || \result == 1;
*/
int64_t func(int64_t x)
{
    int64_t result;
    //@ assert 1 - x == 0 || 1 - x == 1;
    result = 1 - x;
    return result;
}

int main()
{
    return 0;
}

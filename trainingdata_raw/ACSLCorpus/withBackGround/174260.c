#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = 0 <= x <= 1;
*/

/*@
    logic integer func_spec(integer x) = 1 - x;
*/

/*@
    requires is_valid_input(x);
    ensures \result == func_spec(x);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t result;
    //@ assert is_valid_input(x);
    result = 1 - x;
    //@ assert result == func_spec(x);
    return result;
}

/*@
    lemma func_lemma: \forall integer x; is_valid_input(x) ==> func_spec(x) == 1 - x;
*/

/*@
    requires is_valid_input(x);
    ensures \result == func_spec(x);
    assigns \nothing;
*/
uint32_t test_func(uint32_t x)
{
    uint32_t result;
    //@ assert is_valid_input(x);
    //@ assert 1 - x == func_spec(x);
    result = 1 - x;
    //@ assert result == func_spec(x);
    return result;
}

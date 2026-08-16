#include <stddef.h>

/*@
    predicate valid_input(integer a, integer b) =
        0 <= a < 24 && 0 <= b < 24;

    logic integer mod_result(integer a, integer b) =
        (a + b) % 24;

    logic integer final_result(integer a, integer b) =
        mod_result(a, b) < 24 ? mod_result(a, b) : mod_result(a, b) - 24;

    lemma result_in_range:
        \forall integer a, b;
        valid_input(a, b) ==> 0 <= final_result(a, b) < 24;
*/

/*@
    requires valid_input(a, b);
    ensures \result == final_result(a, b);
    ensures 0 <= \result < 24;
*/
size_t func(size_t a, size_t b)
{
    size_t sum;
    size_t result;

    sum = a + b;
    result = sum % 24;

    //@ assert result == mod_result(a, b);

    if (result < 24)
    {
        //@ assert result == final_result(a, b);
        return result;
    }
    else
    {
        //@ assert result - 24 == final_result(a, b);
        return result - 24;
    }
}

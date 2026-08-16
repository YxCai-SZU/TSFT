#include <stdint.h>

/*@
    predicate is_valid_range(integer v) = 1 <= v <= 100;

    logic integer func_spec(integer a, integer b) =
        (a - 2 * b > 0) ? (a - 2 * b) : 0;

    lemma func_lemma:
        \forall integer a, b;
            is_valid_range(a) && is_valid_range(b) ==>
            (func_spec(a, b) == a - 2 * b || func_spec(a, b) == 0) &&
            func_spec(a, b) >= 0;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b);
    requires a == (int64_t)a && b == (int64_t)b;
    ensures \result == a - 2 * b || \result == 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t result;
    //@ assert a - 2 * b > 0 ==> a - 2 * b >= 0;
    //@ assert !(a - 2 * b > 0) ==> 0 >= 0;
    
    if (a - 2 * b > 0) {
        result = a - 2 * b;
    } else {
        result = 0;
    }
    
    return result;
}

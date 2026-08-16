#include <stdint.h>

/*@
    predicate is_valid_range(integer v) =
        1 <= v && v <= 1000000000;
*/

/*@
    logic integer func_spec(integer x, integer t) =
        (x - t > 0) ? (x - t) : 0;
*/

/*@
    lemma func_lemma:
        \forall integer x, t;
            is_valid_range(x) && is_valid_range(t) ==>
            func_spec(x, t) >= 0 &&
            (func_spec(x, t) == x - t || func_spec(x, t) == 0);
*/

/*@
    requires is_valid_range(x) && is_valid_range(t);
    ensures \result >= 0;
    ensures \result == x - t || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t x, int64_t t)
{
    //@ assert is_valid_range(x);
    //@ assert is_valid_range(t);
    //@ assert x == (int64_t)x;
    //@ assert t == (int64_t)t;
    
    int64_t result;
    if (x - t > 0) {
        result = x - t;
    } else {
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == x - t || result == 0;
    return result;
}

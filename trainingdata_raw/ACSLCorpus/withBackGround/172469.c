#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer func_spec(integer a, integer b) =
        a - (b * 2) > 0 ? a - (b * 2) : 0;

    lemma func_lemma:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> func_spec(a, b) >= 0;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result >= 0;
    ensures \result == func_spec(a, b);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t result;
    //@ assert a - (b * 2) >= -10000 && a - (b * 2) <= 10000;
    result = a - (b * 2) > 0 ? a - (b * 2) : 0;
    //@ assert result >= 0;
    return result;
}

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func2(uint64_t a, uint64_t b, uint64_t c, uint64_t d)
{
    int64_t result;
    int64_t temp;
    
    //@ assert a - (b * 2) >= -10000 && a - (b * 2) <= 10000;
    //@ assert (a - (b * 2)) * c >= -100000000 && (a - (b * 2)) * c <= 100000000;
    
    temp = func((int64_t)a, (int64_t)b);
    result = temp * (int64_t)c;
    //@ assert result >= 0;
    return result;
}

#include <stddef.h>

/*@
    predicate valid_params(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer min_val(integer a, integer b, integer c) =
        a < b + c ? a : b + c;

    lemma min_val_property:
        \forall integer a, b, c;
        valid_params(a, b, c) ==>
        (a < b + c ==> min_val(a, b, c) == a) &&
        (a >= b + c ==> min_val(a, b, c) == b + c);
*/

/*@
    requires valid_params(a, b, c);
    ensures \result <= c;
    ensures \result == c || a < b + c;
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t c)
{
    size_t min_val;
    size_t res;

    //@ assert valid_params(a, b, c);
    
    if (a < b + c) {
        min_val = a;
        //@ assert min_val == a;
    } else {
        min_val = b + c;
        //@ assert min_val == b + c;
    }

    //@ assert min_val == min_val(a, b, c);
    
    res = min_val - b;
    
    if (res < c) {
        //@ assert res <= c;
        //@ assert a < b + c;
        return res;
    } else {
        //@ assert c <= c;
        return c;
    }
}

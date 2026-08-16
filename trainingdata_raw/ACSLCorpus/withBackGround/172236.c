#include <stdint.h>

/*@
    predicate in_range(integer v) = -100 <= v <= 100;

    logic integer func_spec(integer a, integer b, integer c) =
        (a == b && b != c) ? c :
        (b == c && a != b) ? a :
        (a == c && a != b) ? b :
        0;

    lemma range_preservation:
        \forall integer a, b, c;
        in_range(a) && in_range(b) && in_range(c) ==>
        (a == b && b != c) ==> in_range(c) &&
        (b == c && a != b) ==> in_range(a) &&
        (a == c && a != b) ==> in_range(b);
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == func_spec(a, b, c);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t result = 0;
    
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    
    if (a == b && b != c) {
        result = c;
    } else if (b == c && a != b) {
        result = a;
    } else if (a == c && a != b) {
        result = b;
    }
    
    //@ assert result == func_spec(a, b, c);
    return result;
}

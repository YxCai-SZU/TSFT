#include <stdbool.h>

/*@
    predicate in_range_i64(integer x) =
        -0x8000000000000000 <= x <= 0x7FFFFFFFFFFFFFFF;

    predicate between(integer a, integer b, integer c) =
        a <= b && a <= c && c <= b;

    lemma range_lemma:
        \forall integer a, b, c;
            in_range_i64(a) && in_range_i64(b) && in_range_i64(c) && a <= b ==>
            (between(a, b, c) <==> (c >= a && c <= b));
*/

/*@
    requires a <= b;
    requires in_range_i64(a);
    requires in_range_i64(b);
    requires in_range_i64(c);
    ensures \result == (c >= a && c <= b);
*/
bool func(long long a, long long b, long long c)
{
    bool result;

    //@ assert in_range_i64(c);
    //@ assert a <= b;
    //@ assert in_range_i64(a) && in_range_i64(b);

    result = (c >= a && c <= b);
    return result;
}

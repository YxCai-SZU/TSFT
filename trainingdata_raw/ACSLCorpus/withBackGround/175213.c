#include <stdbool.h>

/*@
    predicate in_i64_range(integer x) = 
        x >= -9223372036854775808 && x <= 9223372036854775807;

    predicate func_result(integer a, integer b, integer c) =
        a < b && b < c;

    lemma func_lemma:
        \forall integer a, b, c;
        in_i64_range(a) && in_i64_range(b) && in_i64_range(c) ==>
        (a < b && b < c ==> func_result(a, b, c));
*/

/*@
    requires in_i64_range(a);
    requires in_i64_range(b);
    requires in_i64_range(c);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(long long a, long long b, long long c)
{
    //@ assert in_i64_range(a);
    //@ assert in_i64_range(b);
    //@ assert in_i64_range(c);
    //@ assert a < b && b < c ==> func_result(a, b, c);
    return a < b && b < c;
}

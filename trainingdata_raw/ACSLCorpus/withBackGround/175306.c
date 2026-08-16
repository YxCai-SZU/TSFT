#include <stdbool.h>

/*@
    predicate non_negative(integer a, integer b, integer c, integer d, integer e, integer k) =
        a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0 && k >= 0;

    predicate bounded(integer a, integer b, integer c, integer d, integer e, integer k) =
        a <= 123 && b <= 123 && c <= 123 && d <= 123 && e <= 123 && k <= 123;

    predicate condition(integer a, integer b, integer c, integer d, integer e, integer k) =
        (a <= b && c <= d && e <= k + 123 - b - d) || (c <= k) || (b + d >= 123);
*/

/*@
    requires non_negative(a,b,c,d,e,k);
    requires bounded(a,b,c,d,e,k);
    ensures \result == true <==> condition(a,b,c,d,e,k);
    assigns \nothing;
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    bool result;

    //@ assert non_negative(a,b,c,d,e,k);
    //@ assert bounded(a,b,c,d,e,k);

    if ((a <= b && c <= d && e <= k + 123 - b - d) || (c <= k) || (b + d >= 123)) {
        //@ assert condition(a,b,c,d,e,k);
        result = true;
    } else {
        //@ assert !condition(a,b,c,d,e,k);
        result = false;
    }

    //@ assert result == true <==> condition(a,b,c,d,e,k);
    return result;
}

#include <limits.h>

/*@
    predicate valid_range(integer a, integer b) =
        -1000000000 <= a <= b <= 1000000000;

    predicate in_i64_range(integer x) =
        -9223372036854775808 <= x <= 9223372036854775807;

    logic integer max_product(integer a, integer b, integer c, integer d) =
        \max(\max(a*c, a*d), \max(b*c, b*d));
*/

/*@
    requires valid_range(a, b) && valid_range(c, d);
    requires in_i64_range(a) && in_i64_range(b);
    requires in_i64_range(c) && in_i64_range(d);
    ensures \result >= a * c;
    ensures \result >= a * d;
    ensures \result >= b * c;
    ensures \result >= b * d;
    ensures \result == max_product(a, b, c, d);
*/
long long func(long long a, long long b, long long c, long long d)
{
    long long max1;
    long long max2;
    long long ans;
    long long ac;
    long long ad;
    long long bc;
    long long bd;

    //@ assert -1000000000 <= a <= 1000000000;
    //@ assert -1000000000 <= b <= 1000000000;
    //@ assert -1000000000 <= c <= 1000000000;
    //@ assert -1000000000 <= d <= 1000000000;

    ac = a * c;
    //@ assert -1000000000000000000 <= ac <= 1000000000000000000;

    ad = a * d;
    //@ assert -1000000000000000000 <= ad <= 1000000000000000000;

    bc = b * c;
    //@ assert -1000000000000000000 <= bc <= 1000000000000000000;

    bd = b * d;
    //@ assert -1000000000000000000 <= bd <= 1000000000000000000;

    if (ac > ad) {
        max1 = ac;
    } else {
        max1 = ad;
    }

    if (bc > bd) {
        max2 = bc;
    } else {
        max2 = bd;
    }

    if (max1 > max2) {
        ans = max1;
    } else {
        ans = max2;
    }

    return ans;
}

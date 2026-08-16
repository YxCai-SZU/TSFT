#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_in_range:
        \forall integer x, y;
            in_range(x) && in_range(y) ==> 
            -1000000000000000000 <= product(x, y) <= 1000000000000000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires a <= b && c <= d;
    ensures \result == product(b, d) || 
            \result == product(b, c) || 
            \result == product(a, d) || 
            \result == product(a, c);
*/
long long func(long long a, long long b, long long c, long long d)
{
    long long max1;
    long long max2;
    long long ac;
    long long ad;
    long long bc;
    long long bd;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(d);

    //@ assert -1000000000000000000 <= product(a, c) <= 1000000000000000000;
    ac = a * c;

    //@ assert -1000000000000000000 <= product(a, d) <= 1000000000000000000;
    ad = a * d;

    //@ assert -1000000000000000000 <= product(b, c) <= 1000000000000000000;
    bc = b * c;

    //@ assert -1000000000000000000 <= product(b, d) <= 1000000000000000000;
    bd = b * d;

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
        return max1;
    } else {
        return max2;
    }
}

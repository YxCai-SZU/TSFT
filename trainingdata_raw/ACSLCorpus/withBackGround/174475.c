#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate in_range_pair(integer x, integer y) = -1000000000 <= x <= y <= 1000000000;
*/

/*@
    requires in_range_pair(a, b);
    requires in_range_pair(c, d);
    requires a <= INT_MAX && a >= INT_MIN;
    requires b <= INT_MAX && b >= INT_MIN;
    requires c <= INT_MAX && c >= INT_MIN;
    requires d <= INT_MAX && d >= INT_MIN;
    ensures \result == a * d || \result == b * c || \result == a * c || \result == b * d;
*/
long long func(long long a, long long b, long long c, long long d) {
    long long max1;
    long long max2;
    long long res;

    //@ assert a >= -1000000000 && a <= 1000000000;
    //@ assert c >= -1000000000 && c <= 1000000000;
    //@ assert a * c >= -1000000000000000000LL && a * c <= 1000000000000000000LL;
    //@ assert a * d >= -1000000000000000000LL && a * d <= 1000000000000000000LL;

    if (a * c > a * d) {
        max1 = a * c;
    } else {
        max1 = a * d;
    }

    //@ assert b >= -1000000000 && b <= 1000000000;
    //@ assert d >= -1000000000 && d <= 1000000000;
    //@ assert b * d >= -1000000000000000000LL && b * d <= 1000000000000000000LL;
    //@ assert b * c >= -1000000000000000000LL && b * c <= 1000000000000000000LL;

    if (b * c > b * d) {
        max2 = b * c;
    } else {
        max2 = b * d;
    }

    if (max1 > max2) {
        res = max1;
    } else {
        res = max2;
    }

    //@ assert res == a * d || res == b * c || res == a * c || res == b * d;
    return res;
}

int main() {
    return 0;
}

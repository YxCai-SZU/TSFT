#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= (b) <= 1000000000);
    requires (-1000000000 <= (c) <= (d) <= 1000000000);
    requires a <= INT_MAX && a >= INT_MIN;
    requires b <= INT_MAX && b >= INT_MIN;
    requires c <= INT_MAX && c >= INT_MIN;
    requires d <= INT_MAX && d >= INT_MIN;
    ensures \result >= a * c;
    ensures \result >= a * d;
    ensures \result >= b * c;
    ensures \result >= b * d;
    assigns \nothing;
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

    //@ assert -1000000000000000000 <= a * c <= 1000000000000000000;
    ac = a * c;
    //@ assert -1000000000000000000 <= a * d <= 1000000000000000000;
    ad = a * d;
    //@ assert -1000000000000000000 <= b * c <= 1000000000000000000;
    bc = b * c;
    //@ assert -1000000000000000000 <= b * d <= 1000000000000000000;
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
        ans = max1;
    } else {
        ans = max2;
    }

    //@ assert ans >= a * c;
    //@ assert ans >= a * d;
    //@ assert ans >= b * c;
    //@ assert ans >= b * d;
    return ans;
}

#include <stdbool.h>

/*@
    requires 0 <= a <= 123;
    requires 0 <= b <= 123;
    requires 0 <= c <= 123;
    requires 0 <= d <= 123;
    requires 0 <= e <= 123;
    requires 0 <= k <= 123;
    requires a < b && b < c && c < d && d < e;
    ensures \result == (b - a <= k || c - a <= k || d - a <= k || e - a <= k);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int ab;
    int ac;
    int ad;
    int ae;
    int min_ab_ac;
    int min_ab_ac_ad;
    int min_ab_ac_ad_ae;
    bool result;

    //@ assert ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));

    ab = a > b ? a - b : b - a;
    ac = a > c ? a - c : c - a;
    ad = a > d ? a - d : d - a;
    ae = a > e ? a - e : e - a;

    //@ assert ab == ((a) > (b) ? (a) - (b) : (b) - (a));
    //@ assert ac == ((a) > (c) ? (a) - (c) : (c) - (a));
    //@ assert ad == ((a) > (d) ? (a) - (d) : (d) - (a));
    //@ assert ae == ((a) > (e) ? (a) - (e) : (e) - (a));

    min_ab_ac = ab < ac ? ab : ac;
    min_ab_ac_ad = min_ab_ac < ad ? min_ab_ac : ad;
    min_ab_ac_ad_ae = min_ab_ac_ad < ae ? min_ab_ac_ad : ae;

    //@ assert min_ab_ac_ad_ae == (((((a) > (b) ? (a) - (b) : (b) - (a))) < (((a) > (c) ? (a) - (c) : (c) - (a))) ? ((((a) > (b) ? (a) - (b) : (b) - (a))) < (((a) > (d) ? (a) - (d) : (d) - (a))) ? ((((a) > (b) ? (a) - (b) : (b) - (a))) < (((a) > (e) ? (a) - (e) : (e) - (a))) ? (((a) > (b) ? (a) - (b) : (b) - (a))) : (((a) > (e) ? (a) - (e) : (e) - (a)))) : ((((a) > (d) ? (a) - (d) : (d) - (a))) < (((a) > (e) ? (a) - (e) : (e) - (a))) ? (((a) > (d) ? (a) - (d) : (d) - (a))) : (((a) > (e) ? (a) - (e) : (e) - (a))))) :                  ((((a) > (c) ? (a) - (c) : (c) - (a))) < (((a) > (d) ? (a) - (d) : (d) - (a))) ? ((((a) > (c) ? (a) - (c) : (c) - (a))) < (((a) > (e) ? (a) - (e) : (e) - (a))) ? (((a) > (c) ? (a) - (c) : (c) - (a))) : (((a) > (e) ? (a) - (e) : (e) - (a)))) : ((((a) > (d) ? (a) - (d) : (d) - (a))) < (((a) > (e) ? (a) - (e) : (e) - (a))) ? (((a) > (d) ? (a) - (d) : (d) - (a))) : (((a) > (e) ? (a) - (e) : (e) - (a)))))));
    //@ assert min_ab_ac_ad_ae == ab || min_ab_ac_ad_ae == ac || min_ab_ac_ad_ae == ad || min_ab_ac_ad_ae == ae;

    result = min_ab_ac_ad_ae <= k;
    return result;
}

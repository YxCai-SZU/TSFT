#include <limits.h>

/*@
    requires a >= 0 && b >= 0 && c >= 0;
    requires 1 <= k && k <= a + b + c;
    ensures \result <= a;
    ensures \result >= -c;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ans = 0;
    int rst = k;
    int min_a;
    int min_b;
    int min_c;

    //@ assert ((a) >= 0 && (b) >= 0 && (c) >= 0);
    //@ assert (1 <= (k) && (k) <= (a) + (b) + (c));

    min_a = a < rst ? a : rst;
    ans += min_a;
    rst -= min_a;

    //@ assert ans == ((a) < (k) ? (a) : (k));
    //@ assert rst == k - ((a) < (k) ? (a) : (k));

    min_b = b < rst ? b : rst;
    rst -= min_b;

    //@ assert rst == k - ((a) < (k) ? (a) : (k)) - ((b) < (k - ((a) < (k) ? (a) : (k))) ? (b) : (k - ((a) < (k) ? (a) : (k))));

    min_c = c < rst ? c : rst;
    ans -= min_c;
    rst -= min_c;

    //@ assert ans == ((((a)) < ((k)) ? ((a)) : ((k))) - (((c)) < ((k) - (((a)) < ((k)) ? ((a)) : ((k))) - (((b)) < ((k) - (((a)) < ((k)) ? ((a)) : ((k)))) ? ((b)) : ((k) - (((a)) < ((k)) ? ((a)) : ((k)))))) ? ((c)) : ((k) - (((a)) < ((k)) ? ((a)) : ((k))) - (((b)) < ((k) - (((a)) < ((k)) ? ((a)) : ((k)))) ? ((b)) : ((k) - (((a)) < ((k)) ? ((a)) : ((k))))))));
    //@ assert ans <= a;
    //@ assert ans >= -c;

    return ans;
}

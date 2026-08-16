#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 &&
        (k) >= 1 && (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    ensures \result <= a;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t result = 0;
    int32_t rst = k;
    int32_t min_a;
    int32_t min_b;
    int32_t min_c;

    //@ assert ((a) >= 0 && (b) >= 0 && (c) >= 0 &&         (k) >= 1 && (k) <= (a) + (b) + (c) && (k) <= 2000000000);

    if (a < rst) {
        min_a = a;
    } else {
        min_a = rst;
    }
    result += min_a;
    rst -= min_a;

    //@ assert result == (((a) < (k)) ? (a) : (k));

    if (b < rst) {
        min_b = b;
    } else {
        min_b = rst;
    }
    rst -= min_b;

    //@ assert rst == k - (((a) < (k)) ? (a) : (k)) - (((b) < (k - (((a) < (k)) ? (a) : (k)))) ? (b) : (k - (((a) < (k)) ? (a) : (k))));

    if (c < rst) {
        min_c = c;
    } else {
        min_c = rst;
    }
    result -= min_c;

    //@ assert result == (((((a)) < ((k))) ? ((a)) : ((k))) - ((((c)) < ((k) - ((((a)) < ((k))) ? ((a)) : ((k))) - ((((b)) < ((k) - ((((a)) < ((k))) ? ((a)) : ((k))))) ? ((b)) : ((k) - ((((a)) < ((k))) ? ((a)) : ((k))))))) ? ((c)) : ((k) - ((((a)) < ((k))) ? ((a)) : ((k))) - ((((b)) < ((k) - ((((a)) < ((k))) ? ((a)) : ((k))))) ? ((b)) : ((k) - ((((a)) < ((k))) ? ((a)) : ((k))))))));
    //@ assert result <= a;

    return result;
}

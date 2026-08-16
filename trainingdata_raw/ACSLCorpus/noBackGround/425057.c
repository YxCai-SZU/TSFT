#include <stdint.h>

/*@
    requires (\valid((p)) && \valid((p)+1) &&
        (1 <= ((p)[0]) <= 10000) && (1 <= ((p)[1]) <= 10000)) && (\valid((q)) && \valid((q)+1) &&
        (1 <= ((q)[0]) <= 10000) && (1 <= ((q)[1]) <= 10000));
    ensures \result >= 0;
    ensures \result == ((p[0]) * (q[0])) ||
            \result == ((p[1]) * (q[1])) ||
            \result == ((p[0]) * (q[1])) ||
            \result == ((p[1]) * (q[0]));
    assigns \nothing;
*/
int32_t func(int32_t* p, int32_t* q)
{
    // Variable declarations at top of scope
    int32_t x1;
    int32_t x2;
    int32_t x3;
    int32_t x4;
    int32_t max_val;

    //@ assert (1 <= (p[0]) <= 10000);
    //@ assert (1 <= (q[0]) <= 10000);
    //@ assert (1 <= (p[1]) <= 10000);
    //@ assert (1 <= (q[1]) <= 10000);

    //@ assert ((p[0]) * (q[0])) <= 100000000;
    //@ assert ((p[1]) * (q[1])) <= 100000000;
    //@ assert ((p[0]) * (q[1])) <= 100000000;
    //@ assert ((p[1]) * (q[0])) <= 100000000;

    x1 = p[0] * q[0];
    x2 = p[1] * q[1];
    x3 = p[0] * q[1];
    x4 = p[1] * q[0];

    if (x1 > x2) {
        if (x1 > x3) {
            if (x1 > x4) {
                max_val = x1;
            } else {
                max_val = x4;
            }
        } else {
            if (x3 > x4) {
                max_val = x3;
            } else {
                max_val = x4;
            }
        }
    } else {
        if (x2 > x3) {
            if (x2 > x4) {
                max_val = x2;
            } else {
                max_val = x4;
            }
        } else {
            if (x3 > x4) {
                max_val = x3;
            } else {
                max_val = x4;
            }
        }
    }

    //@ assert max_val >= 0;
    return max_val;
}

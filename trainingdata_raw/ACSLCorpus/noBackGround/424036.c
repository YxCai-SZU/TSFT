#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
    ensures \result >= 0;
    ensures \result <= ((a) * 3 + (p));
*/
long func(long a, long p) {
    long sum;
    long ret;
    bool is_odd;
    long temp_sum;

    sum = a * 3 + p;
    ret = 0;
    is_odd = false;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= ((a) * 3 + (p));
        loop invariant temp_sum <= sum;
        loop invariant sum == ((a) * 3 + (p));
        loop invariant (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
        loop assigns temp_sum;
        loop variant temp_sum;
    */
    while (temp_sum >= 2) {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
    }

    if (temp_sum == 1) {
        is_odd = true;
    }

    /*@
        loop invariant 0 <= sum <= ((a) * 3 + (p));
        loop invariant sum <= ((a) * 3 + (p));
        loop invariant (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
        loop invariant ret >= 0;
        loop invariant ret <= (((a) * 3 + (p)) - sum) / 2;
        loop assigns sum, ret;
        loop variant sum;
    */
    while (sum >= 2) {
        //@ assert sum >= 2;
        sum -= 2;
        ret += 1;
    }

    if (is_odd) {
        ret += 1;
    }

    //@ assert ret >= 0;
    //@ assert ret <= ((a) * 3 + (p));

    return ret;
}

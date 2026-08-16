#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
    ensures \result >= 0;
    ensures \result <= ((a) * 3 + (p));
*/
long func(long a, long p) {
    long sum;
    long ans;
    bool is_odd;
    long count;
    long temp_sum;

    sum = a * 3 + p;
    ans = 0;
    is_odd = false;
    count = 0;

    /*@
        loop invariant sum >= 0;
        loop invariant sum <= ((a) * 3 + (p));
        loop invariant count >= 0;
        loop invariant count <= ((a) * 3 + (p)) / 2;
        loop invariant ((a) * 3 + (p)) - sum == count * 2;
        loop invariant (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
        loop assigns sum, count;
        loop variant sum;
    */
    while (sum >= 2) {
        sum -= 2;
        count += 1;
    }
    ans = count;

    temp_sum = a * 3 + p;
    /*@
        loop invariant temp_sum >= 0;
        loop invariant temp_sum <= ((a) * 3 + (p));
        loop invariant (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
        loop assigns temp_sum;
        loop variant temp_sum;
    */
    while (temp_sum >= 2) {
        temp_sum -= 2;
    }

    //@ assert temp_sum == 0 || temp_sum == 1;
    if (temp_sum == 1) {
        is_odd = true;
    }

    if (is_odd) {
        ans += 1;
    }

    //@ assert ans >= 0;
    //@ assert ans <= ((a) * 3 + (p));
    return ans;
}

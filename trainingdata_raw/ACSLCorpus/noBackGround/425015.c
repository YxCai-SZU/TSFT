#include <stdint.h>

/*@
    requires (1 <= (l) <= (r) <= 100 && 1 <= (d) <= 100);
    ensures \result >= 0 && \result <= r - l + 1;
    assigns \nothing;
*/
int64_t func(int64_t l, int64_t r, int64_t d) {
    int64_t ans = 0;
    int64_t i = l;
    int64_t remainder;

    /*@
        loop invariant ((l) <= (i) && (i) <= (r) + 1 &&
        (ans) >= 0 && (ans) <= (i) - (l) &&
        (1 <= ((l)) <= ((r)) <= 100 && 1 <= ((d)) <= 100));
        loop assigns i, ans, remainder;
        loop variant r - i + 1;
    */
    while (i <= r) {
        remainder = i;

        /*@
            loop invariant (1 <= (d) <= 100 && (remainder) >= 0 && (remainder) <= (i));
            loop assigns remainder;
            loop variant remainder;
        */
        while (remainder >= d) {
            //@ assert remainder >= d && remainder <= i;
            remainder -= d;
        }

        //@ assert remainder >= 0 && remainder < d;
        if (remainder == 0) {
            //@ assert ans >= 0 && ans <= i - l;
            ans += 1;
        }
        i += 1;
    }
    //@ assert ans >= 0 && ans <= r - l + 1;
    return ans;
}

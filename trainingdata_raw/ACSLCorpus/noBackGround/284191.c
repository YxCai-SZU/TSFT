#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
    ensures \result >= 0 && \result <= ((a) * 3 + (p));
*/
int64_t func(int64_t a, int64_t p)
{
    // Variable declarations at scope top
    int64_t sum;
    int64_t ans;
    int is_even;

    sum = a * 3 + p;
    ans = 0;
    is_even = 1;

    // First loop: division by 2
    /*@
        loop invariant 0 <= sum && sum <= ((a) * 3 + (p));
        loop invariant 0 <= ans && ans <= ((a) * 3 + (p)) / 2;
        loop invariant ((a) * 3 + (p)) == sum + 2 * ans;
        loop invariant (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
        loop assigns sum, ans;
    */
    while (sum >= 2) {
        //@ assert sum >= 2 && sum <= ((a) * 3 + (p));
        sum -= 2;
        ans += 1;
        //@ assert ((a) * 3 + (p)) == sum + 2 * ans;
    }

    // Second loop: handle negative case (though sum should never be negative)
    /*@
        loop invariant -1 <= sum && sum <= ((a) * 3 + (p));
        loop invariant 0 <= ans && ans <= ((a) * 3 + (p)) / 2;
        loop invariant ((a) * 3 + (p)) == sum + 2 * ans;
        loop invariant (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
        loop assigns sum;
    */
    while (sum < 0) {
        //@ assert sum < 0 && sum >= -1;
        sum += 2;
        //@ assert ((a) * 3 + (p)) == sum + 2 * ans;
    }

    if (sum == 1) {
        is_even = 0;
    }

    //@ assert ans >= 0;
    //@ assert ans <= ((a) * 3 + (p));
    return ans;
}

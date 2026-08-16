#include <stdint.h>

/*@
    requires (0 <= (A) <= 100 && 0 <= (P) <= 100);
    ensures \result >= 0;
    ensures \result <= (A * 3 + P) / 2;
    assigns \nothing;
*/
int32_t func(uint32_t A, uint32_t P) {
    // Variable declarations at scope top
    int32_t ans;
    int32_t temp_sum;
    int32_t count;
    int32_t sum;

    //@ assert 0 <= A <= 100 && 0 <= P <= 100;
    //@ assert A * 3 <= 300;

    sum = A * 3 + P;
    ans = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant (0 <= (temp_sum) <= (sum) &&
        (sum) == (((A)) * 3) + (P) &&
        0 <= (count) <= (sum) / 2 &&
        (ans) == (count) &&
        (temp_sum) == (sum) - 2 * (count) &&
        0 <= (A) <= 100 &&
        0 <= (P) <= 100 &&
        (((A)) * 3) <= 300 &&
        (P) <= 100);
        loop invariant 0 <= temp_sum;
        loop assigns temp_sum, ans, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2) {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        ans += 1;
        count += 1;
        //@ assert temp_sum == sum - 2 * count;
    }

    //@ assert ans >= 0;
    //@ assert ans <= (A * 3 + P) / 2;
    return ans;
}

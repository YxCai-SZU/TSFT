#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (p) <= 100);
    ensures \result <= p + a * 3;
*/
unsigned int func(unsigned int a, unsigned int p) {
    unsigned int sum;
    unsigned int ans;
    bool is_odd;
    unsigned int temp_sum;

    sum = p + a * 3;
    ans = 0;
    is_odd = false;
    temp_sum = sum;

    //@ assert temp_sum == p + a * 3;

    /*@
        loop invariant 0 <= temp_sum <= p + a * 3;
        loop invariant ans <= (p + a * 3 - temp_sum) / 2;
        loop invariant sum == p + a * 3;
        loop assigns temp_sum, ans;
    */
    while (temp_sum >= 2) {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        ans += 1;
    }

    if (temp_sum == 1) {
        is_odd = true;
    }

    if (is_odd) {
        ans += 1;
    }

    //@ assert ans <= p + a * 3;
    return ans;
}

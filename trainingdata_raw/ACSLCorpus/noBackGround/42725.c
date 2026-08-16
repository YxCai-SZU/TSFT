#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (p) <= 100);
    ensures \result >= 0;
    ensures \result <= ((a) * 3 + (p));
*/
int func(int a, int p) {
    int sum;
    int ans;
    bool is_non_zero;
    int count;
    int temp_sum;

    sum = a * 3 + p;
    ans = 0;
    is_non_zero = false;
    count = 0;

    /*@
        loop invariant 0 <= sum <= ((a) * 3 + (p));
        loop invariant 0 <= count <= (((a) * 3 + (p)) - sum) / 2;
        loop invariant sum == ((a) * 3 + (p)) - 2 * count;
        loop invariant (0 <= (a) <= 100 && 0 <= (p) <= 100);
        loop invariant ((a) * 3 + (p)) <= 400;
        loop invariant count <= 200;
        loop assigns sum, count;
    */
    while (sum >= 2) {
        //@ assert sum >= 2;
        sum -= 2;
        count += 1;
    }
    ans = count;

    temp_sum = a * 3 + p;
    /*@
        loop invariant 0 <= temp_sum <= ((a) * 3 + (p));
        loop invariant temp_sum == ((a) * 3 + (p)) - 2 * ((((a) * 3 + (p)) - temp_sum) / 2);
        loop invariant (0 <= (a) <= 100 && 0 <= (p) <= 100);
        loop invariant ((a) * 3 + (p)) <= 400;
        loop invariant temp_sum <= 400;
        loop assigns temp_sum;
    */
    while (temp_sum >= 2) {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
    }

    if (temp_sum == 1) {
        is_non_zero = true;
    }

    if (is_non_zero) {
        ans += 1;
    }

    //@ assert ans >= 0;
    //@ assert ans <= ((a) * 3 + (p));

    return ans;
}

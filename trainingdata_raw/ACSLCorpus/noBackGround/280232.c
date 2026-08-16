#include <stdbool.h>

/*@
    requires \valid(v+(0..len-1));
    requires ((len) >= 2 &&
        1 <= (v)[0] <= 9 &&
        1 <= (v)[1] <= 9);
    ensures \result == (((((v))[(1)]) * 10 + (((v))[(0)])) % 4 == 0);
    assigns \nothing;
*/
bool func(int *v, int len) {
    int sum;
    bool is_divisible = false;
    int temp_sum;

    sum = v[1] * 10 + v[0];
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant temp_sum % 4 == sum % 4;
        loop assigns temp_sum;
    */
    while (temp_sum >= 4) {
        temp_sum -= 4;
    }

    //@ assert temp_sum == sum % 4;
    
    if (temp_sum == 0) {
        is_divisible = true;
    }

    //@ assert is_divisible == (sum % 4 == 0);
    return is_divisible;
}

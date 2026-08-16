#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 9) && (1 <= (g) && (g) <= 9) && (1 <= (b) && (b) <= 9);
    ensures \result == (((g) * 10 + (b)) % 4 == 0);
    assigns \nothing;
*/
bool func(int r, int g, int b) {
    int sum;
    bool is_divisible;
    int temp_sum;

    sum = g * 10 + b;
    //@ assert sum == ((g) * 10 + (b));
    //@ assert 0 <= sum <= 99;

    is_divisible = false;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant temp_sum % 4 == sum % 4;
        loop invariant is_divisible == false;
        loop assigns temp_sum, is_divisible;
        loop variant temp_sum;
    */
    while (temp_sum >= 4) {
        temp_sum -= 4;
    }

    if (temp_sum == 0) {
        is_divisible = true;
    }

    //@ assert is_divisible == (sum % 4 == 0);
    return is_divisible;
}

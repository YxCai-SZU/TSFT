#include <stdbool.h>

/*@
    requires (\valid((s)) && (s)[0] >= 1 && (s)[0] <= 9 &&
        (s)[1] >= 1 && (s)[1] <= 9 &&
        (s)[2] >= 1 && (s)[2] <= 9);
    ensures \result == (((s[0]) * 100 + (s[1]) * 10 + (s[2])) % 4 == 0);
    assigns \nothing;
*/
bool f(int *s) {
    int sum;
    bool is_divisible;
    int abs_sum;
    int temp;

    sum = s[0] * 100 + s[1] * 10 + s[2];
    is_divisible = false;
    abs_sum = sum;

    //@ assert sum >= 0;
    //@ assert abs_sum == sum;

    temp = abs_sum;
    /*@
        loop invariant 0 <= temp <= abs_sum;
        loop invariant temp % 4 == abs_sum % 4;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 4) {
        temp -= 4;
    }

    if (temp == 0) {
        is_divisible = true;
    }

    return is_divisible;
}

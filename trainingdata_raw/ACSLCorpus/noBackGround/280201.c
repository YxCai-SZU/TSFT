#include <stdbool.h>

/*@
    requires \valid(v+(0..2));
    requires ((3) == 3 &&
        1 <= (v)[0] <= 9 &&
        1 <= (v)[1] <= 9 &&
        1 <= (v)[2] <= 9);
    ensures \result == (((v[1]) * 100 + (v[2]) * 10 + (v[0])) % 4 == 0);
    assigns \nothing;
*/
bool func(int *v) {
    int a;
    int b;
    int c;
    int n;
    bool is_divisible;
    int temp_n;

    a = v[0];
    b = v[1];
    c = v[2];
    n = b * 100 + c * 10 + a;
    is_divisible = false;
    temp_n = n;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n % 4 == n % 4;
        loop assigns temp_n;
    */
    while (temp_n >= 4) {
        //@ assert temp_n >= 4;
        temp_n -= 4;
    }

    //@ assert temp_n % 4 == n % 4;
    if (temp_n == 0) {
        is_divisible = true;
    }

    return is_divisible;
}

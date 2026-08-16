#include <stdbool.h>

/*@
    requires (1 <= (X) && (X) <= 100000);
    ensures \result == 0 || \result == 1;
*/
int func(long long X) {
    long long a = 0;
    long long b = 0;
    long long temp_X = X;
    bool is_negative = false;

    if (X < 0) {
        is_negative = true;
        temp_X = -temp_X;
    }

    /*@
        loop invariant (1 <= (X) && (X) <= 100000);
        loop invariant ((temp_X) >= 0);
        loop invariant ((a) >= 0);
        loop invariant ((temp_X) == (X) - 105 * (a));
        loop assigns temp_X, a;
        loop variant temp_X;
    */
    while (temp_X >= 105) {
        temp_X -= 105;
        a += 1;
    }
    a *= is_negative ? -1 : 1;

    /*@
        loop invariant (1 <= (X) && (X) <= 100000);
        loop invariant ((temp_X) >= 0);
        loop invariant ((b) >= 0);
        loop invariant ((temp_X) == (X) - 105 * (a) - 100 * (b));
        loop assigns temp_X, b;
        loop variant temp_X;
    */
    while (temp_X >= 100) {
        temp_X -= 100;
        b += 1;
    }
    b *= is_negative ? -1 : 1;

    long long sum = a + b;
    long long diff = sum < X ? X - sum : sum - X;
    if (diff == 0) {
        return 1;
    } else {
        return 0;
    }
}

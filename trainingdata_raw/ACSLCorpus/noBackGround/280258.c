#include <stdbool.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures (a < 10 && b < 10 ==> \result == a * b) &&
            (a >= 10 || b >= 10 ==> \result == -1);
    assigns \nothing;
*/
int func(int a, int b) {
    int max_ab;
    int result;

    max_ab = (a > b) ? a : b;

    if (max_ab < 10) {
        //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9);
        //@ assert a * b <= 81;
        result = a * b;
    } else {
        result = -1;
    }

    return result;
}

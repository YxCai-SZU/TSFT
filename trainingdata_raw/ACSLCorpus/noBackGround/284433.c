#include <stdbool.h>

/*@
    requires (3 <= (a) && (a) <= 20);
    requires (3 <= (b) && (b) <= 20);
    ensures \result >= 0;
    ensures \result <= a || \result <= b;
    assigns \nothing;
*/
int func(int a, int b)
{
    int res;

    if (a >= b + 1) {
        res = a - (b + 1);
    } else if (b >= a + 1) {
        res = b - (a + 1);
    } else {
        res = 0;
    }

    //@ assert res >= 0;
    //@ assert res <= a || res <= b;

    return res;
}

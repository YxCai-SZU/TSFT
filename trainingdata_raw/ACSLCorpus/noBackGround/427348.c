#include <stdbool.h>

/*@
    requires (3 <= (a) <= 20) && (3 <= (b) <= 20);
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
    assigns \nothing;
*/
int func(int a, int b)
{
    int max;
    int result;

    //@ assert a + b <= 40;
    //@ assert 2 * a - 1 <= 39;
    //@ assert 2 * b - 1 <= 39;
    //@ assert 2 * a - 1 >= 5;

    if (a > b) {
        max = a;
    } else {
        max = b;
    }

    if (max == a) {
        result = a + b;
    } else {
        result = 2 * max - 1;
    }

    //@ assert result == a + b || result == 2 * a - 1 || result == 2 * b - 1;
    return result;
}

#include <limits.h>

/*@
    requires (3 <= (a) <= 20) && (3 <= (b) <= 20);
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
    ensures \result >= 0;
*/
int func(int a, int b)
{
    int min_val;
    int max_val;
    int result;

    //@ assert (3 <= (a) <= 20);
    //@ assert (3 <= (b) <= 20);

    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }

    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }

    //@ assert (3 <= (min_val) <= 20);
    //@ assert (3 <= (max_val) <= 20);

    if (max_val - min_val <= 1) {
        result = a + b;
    } else if (a == 3 && b == 3) {
        result = 2 * a - 1;
    } else {
        result = 2 * b - 1;
    }

    //@ assert result == a + b || result == 2 * a - 1 || result == 2 * b - 1;
    //@ assert result >= 0;

    return result;
}

#include <stdbool.h>

/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result == a + a - 1 || \result == b + b - 1 || \result == a + b || \result == b + a;
*/
int func(int a, int b)
{
    int min_val;
    int max_val;
    int result;

    // Calculate min and max
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

    //@ assert min_val == (a < b ? a : b);
    //@ assert max_val == (a > b ? a : b);

    if (max_val - min_val + 1 < min_val) {
        //@ assert max_val + max_val - 1 == a + a - 1 || max_val + max_val - 1 == b + b - 1;
        result = max_val + max_val - 1;
    } else {
        //@ assert min_val + max_val == a + b || min_val + max_val == b + a;
        result = min_val + max_val;
    }

    return result;
}

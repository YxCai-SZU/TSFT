#include <stdbool.h>

/*@
    requires (3 <= (a) <= 20) && (3 <= (b) <= 20);
    ensures \result == a + b || \result == b * 2 - 1 || \result == a * 2 - 1;
    ensures \result >= 0;
*/
int func(int a, int b) {
    int max_val;
    int min_val;
    int result;

    if (a > b) {
        max_val = a;
        min_val = b;
    } else {
        max_val = b;
        min_val = a;
    }

    //@ assert max_val >= 3 && max_val <= 20;
    //@ assert min_val >= 3 && min_val <= 20;

    if (max_val == min_val) {
        result = max_val * 2 - 1;
    } else if (max_val - min_val == 1) {
        result = max_val + min_val;
    } else {
        result = max_val * 2 - 1;
    }

    return result;
}

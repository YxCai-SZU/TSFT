#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 3 <= v <= 20;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b)
{
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

    //@ assert min_val == a || min_val == b;

    if (max_val > 2 * min_val - 1) {
        //@ assert 2 * min_val - 1 >= 0;
        result = 2 * min_val - 1;
    } else {
        //@ assert a + b >= 0;
        result = a + b;
    }

    return result;
}

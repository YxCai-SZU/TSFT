#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == x + y || \result == x - y || \result == y - x || \result == -x - y;
    assigns \nothing;
*/
int func(int x, int y)
{
    int max_val;
    int min_val;
    int result;

    // Calculate max and min
    if (x > y) {
        max_val = x;
        min_val = y;
    } else {
        max_val = y;
        min_val = x;
    }

    //@ assert (((x) >= (y) && (max_val) == (x)) || ((x) < (y) && (max_val) == (y)));
    //@ assert (((x) <= (y) && (min_val) == (x)) || ((x) > (y) && (min_val) == (y)));
    //@ assert max_val >= min_val;

    if (max_val == x) {
        //@ assert max_val == x;
        //@ assert min_val == y;
        result = x + y;
    } else {
        //@ assert max_val == y;
        //@ assert min_val == x;
        result = x - y;
    }

    // Final verification
    //@ assert result == x + y || result == x - y || result == y - x || result == -x - y;
    return result;
}

#include <limits.h>

/*@
    predicate valid_range(integer a) = 3 <= a <= 20;
    predicate valid_range_b(integer b) = 3 <= b <= 20;
*/

/*@
    requires valid_range(a) && valid_range_b(b);
    ensures \result == a * 2 - 1 || \result == b * 2 - 1 || \result == a + b || \result == b * 2;
    ensures \result >= 0;
*/
int func(int a, int b) {
    int result = 0;

    if (a > b + 1) {
        //@ assert a > b + 1;
        //@ assert a * 2 - 1 <= 39;
        result = a * 2 - 1;
    } else if (b > a + 1) {
        //@ assert b > a + 1;
        //@ assert b * 2 - 1 <= 39;
        result = b * 2 - 1;
    } else if (b == a) {
        //@ assert b == a;
        //@ assert b * 2 <= 40;
        result = b * 2;
    } else {
        //@ assert a <= b + 1 && b <= a + 1;
        //@ assert a + b <= 40;
        result = b + a;
    }

    //@ assert result == a * 2 - 1 || result == b * 2 - 1 || result == a + b || result == b * 2;
    return result;
}

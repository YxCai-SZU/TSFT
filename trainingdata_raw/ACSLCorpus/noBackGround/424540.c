#include <stdbool.h>

/*@
    requires 3 <= a && a <= 20;
    requires 3 <= b && b <= 20;
    ensures \result == a + a - 1 || \result == a + b || \result == b + b - 1;
    ensures \result >= 0;
*/
int func(int a, int b)
{
    int max_ab;
    int min_ab;
    int result;

    if (a > b) {
        max_ab = a;
    } else {
        max_ab = b;
    }

    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }

    //@ assert (((a) > (b) ==> (max_ab) == (a)) && ((a) <= (b) ==> (max_ab) == (b)));
    //@ assert (((a) < (b) ==> (min_ab) == (a)) && ((a) >= (b) ==> (min_ab) == (b)));

    if (max_ab == a) {
        //@ assert max_ab == a;
        result = a + max_ab - 1;
    } else {
        //@ assert max_ab == b;
        result = max_ab + min_ab;
    }

    return result;
}

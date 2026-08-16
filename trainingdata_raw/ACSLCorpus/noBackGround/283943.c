#include <stdbool.h>

/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result >= 0;
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
*/
int func(int a, int b)
{
    int max;
    int min;
    int result;

    if (a > b) {
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }

    //@ assert max >= 3 && max <= 20;
    //@ assert min >= 3 && min <= 20;

    if (max - min == 1) {
        //@ assert max + min >= 0;
        result = max + min;
    } else {
        //@ assert 2 * max - 1 >= 0;
        result = 2 * max - 1;
    }

    return result;
}

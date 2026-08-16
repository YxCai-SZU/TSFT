#include <stdbool.h>

/*@
    requires ((x) != (y) && 1 <= (x) && (x) <= 3 && 1 <= (y) && (y) <= 3);
    ensures \result == (6 - (x) - (y));
    ensures 1 <= \result && \result <= 3;
*/
int func(int x, int y)
{
    int result;

    //@ assert x != y;
    //@ assert 1 <= x && x <= 3;
    //@ assert 1 <= y && y <= 3;

    if (x == 1 && y == 2) {
        result = 3;
    } else if (x == 1 && y == 3) {
        result = 2;
    } else if (x == 2 && y == 1) {
        result = 3;
    } else if (x == 2 && y == 3) {
        result = 1;
    } else if (x == 3 && y == 1) {
        result = 2;
    } else if (x == 3 && y == 2) {
        result = 1;
    } else {
        //@ assert false;
        result = 0;
    }

    //@ assert result == 6 - x - y;
    //@ assert 1 <= result && result <= 3;

    return result;
}

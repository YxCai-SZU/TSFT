#include <stdbool.h>

/*@
    predicate in_range(integer x, integer y) =
        1 <= x && x <= y && y <= 100;

    logic integer distance(integer i, integer y) = y - i;
*/

/*@
    requires in_range(x, y);
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> (x == y || y - x == 1);
*/
int func(int x, int y) {
    // Variable declarations at scope top
    int result;
    int cnt;
    int i;

    if (x == y) {
        result = 1;
    } else if (y - x == 1) {
        result = 1;
    } else {
        cnt = 0;
        i = x;
        /*@
            loop invariant x <= i <= y;
            loop invariant cnt == i - x;
            loop invariant cnt <= y - x;
            loop assigns cnt, i;
        */
        while (i < y) {
            //@ assert cnt == i - x;
            cnt += 1;
            i += 1;
        }
        if (cnt == 1) {
            result = 1;
        } else {
            result = 0;
        }
    }
    //@ assert result == 0 || result == 1;
    return result;
}

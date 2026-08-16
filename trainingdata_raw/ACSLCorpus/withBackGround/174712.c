/*@
    logic integer mymod(integer x, integer y) = x - (x / y) * y;

    lemma lemma_mod:
        \forall integer x, y;
            y > 0 && x >= 0 ==>
                mymod(x, y) >= 0 &&
                mymod(x, y) < y &&
                mymod(x, y) == x - (x / y) * y;
*/

#include <stdbool.h>

/*@
    requires y > 0 && x >= 0;
    ensures \result == mymod(x, y);
    ensures \result >= 0;
    ensures \result < y;
*/
int compute_mod(int x, int y) {
    //@ assert y > 0 && x >= 0;
    int result = x - (x / y) * y;
    //@ assert result == mymod(x, y);
    //@ assert result >= 0;
    //@ assert result < y;
    return result;
}

void test() {
    int x = 20;
    int y = 10;
    //@ assert y > 0 && x >= 0;
    int result = compute_mod(x, y);
    //@ assert result == 0;
}

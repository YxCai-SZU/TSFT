#include <stdbool.h>

/*@
    predicate both_true(bool x, bool y) = x && y;

    lemma example_9: \forall bool x, bool y; both_true(x, y) ==> x && y;
    lemma example_10: \forall integer x, integer y; x > 0 && y > 0 && x < y ==> x + 2 < y + 3;
*/

/*@
    requires x && y == true;
    ensures \result == 0;
    assigns \nothing;
*/
int example_9_impl(bool x, bool y) {
    //@ assert both_true(x, y);
    //@ assert x == true && y == true;
    return 0;
}

/*@
    requires x > 0 && y > 0 && x < y;
    ensures \result == 0;
    assigns \nothing;
*/
int example_10_impl(int x, int y) {
    //@ assert x + 2 < y + 3;
    return 0;
}

int main() {
    return 0;
}

#include <stdbool.h>

/*@
    predicate g(integer x, integer y) = x + y >= 5;

    lemma lemma_g_proves_f:
        \forall integer x, integer y; g(x, y) ==> \true;

    lemma test_g_proves_f:
        \forall integer x; (\exists integer y; g(x, y)) ==> \true;

    logic integer f(integer x) = 1;
*/

/*@
    requires \exists integer y; g(x, y);
    ensures \true;
*/
void test_g_proves_f(int x) {
    //@ assert \exists integer y; g(x, y);
}

int main() {
    return 0;
}

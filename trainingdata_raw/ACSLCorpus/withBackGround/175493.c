#include <stdbool.h>

/*@
    predicate equation_holds(integer a) = a + 2 == a + 1 + 1;
 */

/*@
    lemma test_equation: \forall integer a; equation_holds(a) ==> equation_holds(a);
 */

/*@
    requires equation_holds(a);
    ensures equation_holds(a);
 */
void test_equation_proof(int a) {
    //@ assert equation_holds(a);
}

int main() {
    return 0;
}

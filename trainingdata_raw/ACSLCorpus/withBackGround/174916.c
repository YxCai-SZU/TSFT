#include <stdbool.h>

/*@ predicate f(integer i) = \true; */
/*@ predicate g(integer i, integer j) = \true; */

/*@ lemma lemma_even_f: \forall integer i; i % 2 == 0 ==> f(i); */

/*@ lemma lemma_g_proves_f: \forall integer i, integer j; g(i, j) ==> f(i); */

/*@ lemma test_even_f: \forall integer i; i % 2 == 0 ==> f(i); */

/*@ lemma test_g_proves_f: \forall integer i; (\exists integer j; g(i, j)) ==> f(i); */

int main() {
    return 0;
}

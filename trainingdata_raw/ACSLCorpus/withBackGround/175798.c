#include <stdbool.h>

/*@ predicate f(integer x) = \true; */

/*@ lemma lemma_even_f: \forall integer i; 0 <= i <= 100 && i % 2 == 0 ==> f(i); */

/*@
    requires \forall integer i; 0 <= i <= 100 && i % 2 == 0 ==> f(i);
    ensures \true;
*/
void test_even_f() {
    //@ assert \forall integer i; 0 <= i <= 100 && i % 2 == 0 ==> f(i);
}

/*@ predicate g(integer i, integer j) = \true; */

/*@ lemma lemma_g_proves_f: \forall integer i, j; g(i, j) ==> f(i); */

/*@
    requires \exists integer j; g(i, j);
    ensures f(i);
*/
void test_g_proves_f(int i) {
    //@ assert \exists integer j; g(i, j);
    //@ assert f(i);
}

/*@ predicate h(integer i, integer k) = \true; */

/*@ lemma lemma_h_proves_f: \forall integer i, k; h(i, k) ==> f(i); */

/*@
    requires \exists integer k; h(i, k);
    ensures f(i);
*/
void test_h_proves_f(int i) {
    //@ assert \exists integer k; h(i, k);
    //@ assert f(i);
}

int main() {
    return 0;
}

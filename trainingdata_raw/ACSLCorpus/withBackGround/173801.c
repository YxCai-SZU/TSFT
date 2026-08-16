/*@
predicate f(integer i) = \true;

lemma lemma_even_f:
    \forall integer i; 0 <= i && i <= 100 && i % 2 == 0 ==> f(i);

predicate is_even(integer i) = i % 2 == 0;
*/

/*@
    requires 0 <= i && i <= 100 && i % 2 == 0;
    ensures f(i);
    assigns \nothing;
*/
void lemma_even_f_proof(int i) {
    //@ assert i % 2 == 0;
}

/*@
    ensures \forall integer i; 0 <= i && i <= 100 && i % 2 == 0 ==> f(i);
    assigns \nothing;
*/
void test_even_f_proof() {
    int i;
    /*@
        loop invariant 0 <= i <= 101;
        loop invariant \forall integer j; 0 <= j < i && j % 2 == 0 ==> f(j);
        loop assigns i;
    */
    for (i = 0; i <= 100; ++i) {
        if (i % 2 == 0) {
            lemma_even_f_proof(i);
        }
    }
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}

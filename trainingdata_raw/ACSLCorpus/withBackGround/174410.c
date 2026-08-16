/*@
predicate f(integer i) = \true;

lemma lemma_even_f:
    \forall integer i; i % 2 == 0 ==> f(i);
*/

/*@
requires i % 2 == 0;
ensures f(i);
assigns \nothing;
*/
void lemma_even_f_proof(int i) {
    //@ assert \true;
}

/*@
ensures \forall integer i; i % 2 == 0 ==> f(i);
assigns \nothing;
*/
void test_even_f() {
    int i = 0;
    /*@
    loop invariant 0 <= i <= 10;
    loop invariant \forall integer j; 0 <= j < i && j % 2 == 0 ==> f(j);
    loop assigns i;
    */
    for (i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            lemma_even_f_proof(i);
        }
    }
}

/*@
assigns \nothing;
ensures \result == 0;
*/
int main() {
    test_even_f();
    return 0;
}

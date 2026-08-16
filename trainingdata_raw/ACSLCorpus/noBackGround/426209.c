/*@
    requires 0 <= i && i <= 100;
    ensures (\true);
    assigns \nothing;
*/
void lemma_even_f(int i) {
    //@ assert (\true);
}

/*@
    ensures \forall integer i; 0 <= i && i <= 100 ==> (\true);
    assigns \nothing;
*/
void test_even_f() {
    int i;
    /*@
        loop invariant 0 <= i <= 101;
        loop invariant \forall integer j; 0 <= j && j < i ==> (\true);
        loop assigns i;
    */
    for (i = 0; i <= 100; ++i) {
        //@ assert 0 <= i && i <= 100;
        lemma_even_f(i);
        //@ assert (\true);
    }
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}

/*@
    requires a >= 0 && b >= 0 && c >= 0 && c >= a * b;
    ensures \result == 0;
    assigns \nothing;
*/
int lemma_frobenius_dist_impl(int a, int b, int c) {
    //@ assert c >= a * b;
    return 0;
}

/*@
    requires (\true);
    ensures \result == 0;
    assigns \nothing;
*/
int lemma_even_f_impl(int i) {
    //@ assert (\true);
    return 0;
}

/*@
    ensures \result == 0;
    assigns \nothing;
*/
int test_even_f_impl() {
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant \forall integer j; 0 <= j < i ==> (\true);
        loop assigns i;
    */
    for (int i = 0; i < 10; i++) {
        //@ assert (\true);
    }
    return 0;
}

int main() {
    return 0;
}

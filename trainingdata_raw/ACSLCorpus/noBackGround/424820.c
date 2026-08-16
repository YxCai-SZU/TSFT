/*@
    requires ((i) % 2 == 0);
    ensures ((((i)) % 2 == 0) || (((i)) % 2 != 0));
    assigns \nothing;
*/
void lemma_even_f(int i) {
    //@ assert ((((i)) % 2 == 0) || (((i)) % 2 != 0));
}

/*@
    requires ((i) % 2 != 0);
    ensures ((((i)) % 2 == 0) || (((i)) % 2 != 0));
    assigns \nothing;
*/
void lemma_odd_f(int i) {
    //@ assert ((((i)) % 2 == 0) || (((i)) % 2 != 0));
}

/*@
    ensures \forall integer i; 0 <= i <= 100 && ((i) % 2 == 0) ==> ((((i)) % 2 == 0) || (((i)) % 2 != 0));
    assigns \nothing;
*/
void test_even_f() {
    int i;
    /*@
        loop invariant 0 <= i <= 101;
        loop invariant \forall integer j; 0 <= j < i && ((j) % 2 == 0) ==> ((((j)) % 2 == 0) || (((j)) % 2 != 0));
        loop assigns i;
    */
    for (i = 0; i <= 100; i++) {
        if (i % 2 == 0) {
            lemma_even_f(i);
        }
    }
}

/*@
    ensures \forall integer i; 0 <= i <= 100 && ((i) % 2 != 0) ==> ((((i)) % 2 == 0) || (((i)) % 2 != 0));
    assigns \nothing;
*/
void test_odd_f() {
    int i;
    /*@
        loop invariant 0 <= i <= 101;
        loop invariant \forall integer j; 0 <= j < i && ((j) % 2 != 0) ==> ((((j)) % 2 == 0) || (((j)) % 2 != 0));
        loop assigns i;
    */
    for (i = 0; i <= 100; i++) {
        if (i % 2 != 0) {
            lemma_odd_f(i);
        }
    }
}

/*@
    assigns \nothing;
*/
int main() {
    test_even_f();
    test_odd_f();
    return 0;
}

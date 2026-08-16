/*@
requires ((x) > 0);
ensures x >= 0;
*/
void lemma_is_even(int x) {
    //@ assert ((x) > 0);
}

/*@
ensures \forall integer x; ((x) > 0) ==> x >= 0;
*/
void test_even_f() {
    /*@
    loop invariant 0 <= i <= 100;
    loop invariant \forall integer j; 0 <= j < i ==> (((j) > 0) ==> j >= 0);
    loop assigns i;
    */
    for (int i = 0; i < 100; i++) {
        //@ assert ((i) > 0) ==> i >= 0;
    }
}

int main() {
    return 0;
}

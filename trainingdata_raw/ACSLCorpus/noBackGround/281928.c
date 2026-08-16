/*@
requires ((x) % 2 != 0);
ensures ((((x)) % 2 != 0));
*/
void lemma_odd_f_proof(int x) {
    //@ assert ((((x)) % 2 != 0));
}

/*@
ensures \forall integer i; ((i) % 2 != 0) ==> ((((i)) % 2 != 0));
*/
void test_odd_f() {
    //@ assert \forall integer i; ((i) % 2 != 0) ==> ((((i)) % 2 != 0));
}

int main() {
    return 0;
}

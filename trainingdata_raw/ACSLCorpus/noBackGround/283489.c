/*@
requires ((n) >= 0);
ensures 0 <= n + 1;
*/
void lemma_0_less_than_natural_plus_1_proof(int n) {
    //@ assert ((n) >= 0);
    if (n == 0) {
        //@ assert 0 <= 0 + 1;
    } else {
        //@ assert ((n - 1) >= 0);
        lemma_0_less_than_natural_plus_1_proof(n - 1);
        //@ assert 0 <= (n - 1) + 1;
        //@ assert 0 <= n;
    }
}

int main() {
    return 0;
}

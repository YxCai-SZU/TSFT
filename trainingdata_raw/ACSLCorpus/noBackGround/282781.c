/*@
requires \exists integer j; (\true);
ensures (\true);
*/
void test_g_proves_f(int i) {
    //@ assert \exists integer j; (\true);
    //@ assert (\true);
}

/*@
requires (\true);
requires (\true);
ensures \true;
*/
void lemma_even_f_necessary(int i) {
    //@ assert (\true);
}

/*@
requires (\true);
requires (\true);
ensures \true;
*/
void lemma_g_proves_f_necessary(int i, int j) {
    //@ assert (\true);
}

int main() {
    return 0;
}

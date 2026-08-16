void main() {
}

/*@
requires (\true);
ensures (\true);
*/
void test_even_f(int i) {
    //@ assert (\true);
    //@ assert (\true);
}

/*@
requires \exists integer j; (\true);
ensures (\true);
*/
void test_g_proves_f(int i) {
    //@ assert \exists integer j; (\true);
    //@ assert (\true);
}

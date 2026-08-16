/*@
requires \exists integer j; ((i) > (j));
ensures ((((i)) % 2 == 0) || (((i)) % 2 != 0));
*/
void test_g_proves_f(int i) {
    //@ assert \exists integer j; ((i) > (j));
    //@ assert ((((i)) % 2 == 0) || (((i)) % 2 != 0));
}

int main() {
    return 0;
}

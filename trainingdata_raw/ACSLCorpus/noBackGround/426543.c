/*@
    requires i > 0;
    ensures ((i) * 10 + 5) < ((i + 2) * 10 + 5);
*/
void test_even_f(int i) {
    //@ assert ((i) * 10 + 5) < ((i + 2) * 10 + 5);
}

int main() {
    return 0;
}

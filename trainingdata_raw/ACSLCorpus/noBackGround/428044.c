/*@
    requires ((x) % 2 == 0);
    ensures \exists integer y; ((x+y) % 2 == 0);
*/
void test_even_add_concrete(int x) {
    //@ assert ((x) % 2 == 0);
    //@ assert ((x+2) % 2 == 0);
}

int main() {
    return 0;
}

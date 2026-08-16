/*@
requires ((i) % 2 == 0);
ensures \result % 2 == 0;
*/
int lemma_even_g_wrapper(int i) {
    //@ assert ((i) % 2 == 0);
    //@ assert i % 2 == 0;
    return i;
}

/*@
ensures \forall integer i; ((i) % 2 == 0) ==> i % 2 == 0;
*/
void test_even_g_wrapper() {
    //@ assert \forall integer i; ((i) % 2 == 0) ==> i % 2 == 0;
}

int main() {
    int i;
    
    // Test case 1: even number
    i = 4;
    //@ assert ((i) % 2 == 0);
    lemma_even_g_wrapper(i);
    
    // Test case 2: verify the universal property
    test_even_g_wrapper();
    
    return 0;
}

/*@
    requires \true;
    ensures \forall integer i; (i % 2 == 0) ==> (\true);
*/
void test_even_f2() {
    //@ assert \forall integer i; (i % 2 == 0) ==> (\true);
}

int main() {
    test_even_f2();
    return 0;
}

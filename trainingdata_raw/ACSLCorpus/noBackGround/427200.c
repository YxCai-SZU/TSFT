/*@
    requires 0 <= x <= 100 && 0 <= y <= 100 && 0 <= z <= 100;
    ensures \result == x * (y + z) && \result == x * y + x * z;
*/
unsigned int verify_mul_is_distributive_add_evidence(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert x * (y + z) == x * y + x * z;
    return x * (y + z);
}

/*@
    ensures \forall integer i; 0 <= i <= 100 && i % 2 == 0 ==> (\true);
*/
void test_even_f() {
    //@ assert \forall integer i; 0 <= i <= 100 && i % 2 == 0 ==> (\true);
}

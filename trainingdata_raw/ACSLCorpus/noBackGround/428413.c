/*@
    requires (0 <= (x) && (x) <= 8) && (0 <= (y) && (y) <= 8);
    ensures \result <= 1000;
*/
unsigned int nonlinear_example(unsigned int x, unsigned int y) {
    //@ assert x * y <= 100;
    //@ assert x * y <= 1000;
    return x * y;
}

/*@
    requires (0 <= (x) && (x) <= 8) && (0 <= (y) && (y) <= 8);
    ensures \result <= 64;
*/
unsigned int lemma_application(unsigned int x, unsigned int y) {
    //@ assert x * y <= 64;
    return x * y;
}

/*@
    requires (0 <= (x) && (x) <= 8) && (0 <= (y) && (y) <= 8) && (0 <= (z) && (z) <= 8);
    ensures \result == x * y + x * z;
*/
unsigned int nonlinear_example_distributive(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert x * (y + z) == x * y + x * z;
    return x * (y + z);
}

/*@
    requires (0 <= (x) && (x) <= 8) && (0 <= (y) && (y) <= 8) && (0 <= (z) && (z) <= 8);
    ensures \result == x * y + x * z;
*/
unsigned int lemma_mul_is_distributive_add(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert x * (y + z) == x * y + x * z;
    return x * (y + z);
}

/*@
    requires (0 <= (x) && (x) <= 8) && (0 <= (y) && (y) <= 8) && (0 <= (z) && (z) <= 8);
    ensures \result == x * y + x * z;
*/
unsigned int lemma_mul_is_distributive_add_takes_priority(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert x * (y + z) == x * y + x * z;
    return x * (y + z);
}

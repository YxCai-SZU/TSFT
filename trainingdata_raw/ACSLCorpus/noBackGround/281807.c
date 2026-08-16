/*@
    requires a > 0 && b > 0;
    ensures \result == 0;
    assigns \nothing;
*/
int nonlinear_arith_example14(int a, int b) {
    //@ assert a > 0 && b > 0;
    //@ assert (a + b) * b == a * b + b * b;
    return 0;
}

/*@
    requires x >= 0 && y >= 0 && z >= 0;
    requires x + y <= 10000;
    requires x * z <= 10000;
    requires y * z <= 10000;
    ensures \result == 0;
    assigns \nothing;
*/
int lemma_mul_is_distributive_add(int x, int y, int z) {
    //@ assert x >= 0 && y >= 0 && z >= 0;
    //@ assert x + y <= 10000;
    //@ assert x * z <= 10000;
    //@ assert y * z <= 10000;
    //@ assert x * z + y * z == (x + y) * z;
    return 0;
}

/*@
    requires x >= 0 && y >= 0 && z >= 0;
    requires x + y <= 10000;
    requires x * z <= 10000;
    requires y * z <= 10000;
    ensures \result == 0;
    assigns \nothing;
*/
int lemma_mul_is_distributive_add_minus(int x, int y, int z) {
    //@ assert x >= 0 && y >= 0 && z >= 0;
    //@ assert x + y <= 10000;
    //@ assert x * z <= 10000;
    //@ assert y * z <= 10000;
    //@ assert x * z - y * z == (x - y) * z;
    return 0;
}

int main() {
    return 0;
}

/*@
    requires (0 <= (a) && (a) <= 8 &&
        0 <= (b) && (b) <= 8);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
unsigned int non_linear_arith_example(unsigned int a, unsigned int b) {
    // Variable declarations at scope top
    unsigned int result;

    //@ assert a <= 8;
    //@ assert b <= 8;
    //@ assert a * b <= 64;

    result = a * b;
    return result;
}

int main() {
    non_linear_arith_example(4, 5);
    return 0;
}

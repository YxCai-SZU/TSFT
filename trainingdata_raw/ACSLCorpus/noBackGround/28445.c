/*@
    requires (0 <= (x) && (x) <= (y));
    ensures ((x) * (x) <= (y) * (y));
*/
void non_linear_arith_example(int x, int y) {
    //@ assert (0 <= (x) && (x) <= (y));
    //@ assert ((x) * (x) <= (y) * (y));
}

/*@
    requires (1 <= (x) && (x) <= 10 && 1 <= (y) && (y) <= 10);
    ensures ((x) * (y) <= 100);
*/
void product_bound_check(int x, int y) {
    //@ assert (1 <= (x) && (x) <= 10 && 1 <= (y) && (y) <= 10);
    //@ assert ((x) * (y) <= 100);
}

/*@
    requires ((y) != 0);
    ensures (((x) / (y)) * (y) + (x) % (y) == (x));
*/
void division_product(unsigned int x, unsigned int y) {
    //@ assert ((y) != 0);
    //@ assert (((x) / (y)) * (y) + (x) % (y) == (x));
}

int main() {
    return 0;
}

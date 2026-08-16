/*@
    requires ((n) <= 10 && (m) <= 10);
    ensures \result == n * m;
    assigns \nothing;
*/
unsigned int prod_multistep(unsigned int n, unsigned int m) {
    unsigned int product;
    unsigned int i;

    product = 1;
    i = 0;

    /*@
        loop invariant ((product) == 1 && (i) <= 1);
        loop invariant ((n) <= 10 && (m) <= 10);
        loop assigns product, i;
        loop variant 1 - i;
    */
    while (i < 1) {
        product = 1;
        i += 1;
    }

    //@ assert product * n <= 100;
    //@ assert product * n * m <= 1000;

    return product * n * m;
}

int main() {
    return 0;
}

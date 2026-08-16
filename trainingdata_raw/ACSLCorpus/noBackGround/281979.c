#include <stdint.h>

/*@
    requires ((a) < 10 && (b) < 10 && (c) < 10 && (d) < 10);
    ensures \result == 0;
*/
int complex_modular_arith(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    // Variable declarations at scope top
    unsigned int sum_ab;
    unsigned int sum_cd;
    unsigned int product;
    unsigned int mod_ab;
    unsigned int mod_cd;
    unsigned int mod_product;
    int result = 0;

    //@ assert a < 10 && b < 10 && c < 10 && d < 10;

    sum_ab = a + b;
    //@ assert sum_ab < 20;
    mod_ab = sum_ab % 10;
    //@ assert mod_ab < 10;

    sum_cd = c + d;
    //@ assert sum_cd < 20;
    mod_cd = sum_cd % 10;
    //@ assert mod_cd < 10;

    product = sum_ab * sum_cd;
    //@ assert product < 400;
    mod_product = product % 100;
    //@ assert mod_product < 100;

    return result;
}

int main() {
    return 0;
}

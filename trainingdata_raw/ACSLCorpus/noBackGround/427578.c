/*@
    requires 1 <= a && a <= 3;
    requires 1 <= b && b <= 3;
    ensures \result == ((a * b) % 2 != 0);
*/
int func(int a, int b) {
    int product;
    int remainder;
    int original_product;

    //@ assert (1 <= (a) && (a) <= 3 && 1 <= (b) && (b) <= 3 && 1 <= (a) * (b) && (a) * (b) <= 9);
    //@ assert 1 <= a * b && a * b <= 9;

    product = a * b;
    original_product = product;
    remainder = product;

    if (remainder < 0) {
        remainder = -remainder;
    }

    /*@
        loop invariant 0 <= remainder <= 9;
        loop invariant remainder == original_product - 2 * ((original_product - remainder) / 2);
        loop assigns remainder;
    */
    while (remainder >= 2) {
        remainder -= 2;
    }

    if (original_product < 0) {
        remainder = -remainder;
    }

    //@ assert remainder == ((original_product) >= 0 ?             (original_product) - (2) * ((original_product) / (2)) :             -( (-(original_product)) - (2) * ((-(original_product)) / (2)) ));
    //@ assert remainder == original_product % 2;

    return remainder != 0;
}

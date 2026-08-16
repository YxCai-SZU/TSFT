/*@ requires 1 <= r <= 100;
    ensures \result == 2 * r * 3142 / 1000;
*/
long func(long r)
{
    long scaled_pi;
    long product;
    long divisor;
    long result;
    long temp_product;

    scaled_pi = 3142;
    product = 2 * r * scaled_pi;
    divisor = 1000;
    result = 0;
    temp_product = product;

    /*@
        loop invariant (1 <= (r) <= 100 &&
        (scaled_pi) == 3142 &&
        (product) == 2 * (r) * (scaled_pi) &&
        (divisor) == 1000 &&
        (result) * (divisor) + (temp_product) == (product) &&
        0 <= (result) &&
        (temp_product) >= 0);
        loop assigns temp_product, result;
        loop variant temp_product;
    */
    while (temp_product >= divisor) {
        //@ assert (1 <= (r) <= 100 &&         (scaled_pi) == 3142 &&         (product) == 2 * (r) * (scaled_pi) &&         (divisor) == 1000 &&         (result) * (divisor) + (temp_product) == (product) &&         0 <= (result) &&         (temp_product) >= 0) && temp_product >= divisor;
        temp_product -= divisor;
        result += 1;
    }

    return result;
}

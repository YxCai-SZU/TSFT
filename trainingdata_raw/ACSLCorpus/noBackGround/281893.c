/*@
    requires 1 <= r <= 100;
    ensures \result == (2 * r * 3142) / 1000;
*/
int func(int r)
{
    // Variable declarations at scope top
    int pi = 3142;
    int two = 2;
    int scale = 1000;
    int product = r * two * pi;
    int result = 0;
    int remainder = product;

    //@ assert (1 <= (r) <= 100 && (product) == (r) * 2 * 3142);
    //@ assert scale == 1000;

    /*@
        loop invariant ((1 <= ((r)) <= 100 && ((product)) == ((r)) * 2 * 3142) &&
        (scale) == 1000 &&
        (result) * (scale) + (remainder) == (product) &&
        0 <= (remainder) < (scale) + (product));
        loop assigns result, remainder;
    */
    while (remainder >= scale) {
        //@ assert remainder >= scale;
        result += 1;
        remainder -= scale;
        //@ assert result * scale + remainder == product;
    }

    //@ assert remainder < scale;
    //@ assert result == ((2 * (r) * 3142) / 1000);
    return result;
}

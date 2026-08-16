/*@
    requires (1 <= (n) <= 10000);
    ensures \result == (1000 * (((n)) / 1000) +
        100 * ((((n)) % 1000) / 100) +
        10 * (((((n)) % 1000) % 100) / 10) +
        (((((n)) % 1000) % 100) % 10));
    assigns \nothing;
*/
int func(int n)
{
    int num = n;
    int sum = 0;
    int quotient_1000 = 0;
    int remainder_1000 = num;

    /*@
        loop invariant 0 <= quotient_1000 <= ((n) / 1000);
        loop invariant remainder_1000 == n - quotient_1000 * 1000;
        loop invariant remainder_1000 >= 0;
        loop assigns quotient_1000, remainder_1000;
        loop variant remainder_1000;
    */
    while (remainder_1000 >= 1000)
    {
        quotient_1000 += 1;
        remainder_1000 -= 1000;
    }

    sum += 1000 * quotient_1000;
    num = remainder_1000;

    int quotient_100 = 0;
    int remainder_100 = num;

    /*@
        loop invariant 0 <= quotient_100 <= (((n) % 1000) / 100);
        loop invariant remainder_100 == ((n) % 1000) - quotient_100 * 100;
        loop invariant remainder_100 >= 0;
        loop assigns quotient_100, remainder_100;
        loop variant remainder_100;
    */
    while (remainder_100 >= 100)
    {
        quotient_100 += 1;
        remainder_100 -= 100;
    }

    sum += 100 * quotient_100;
    num = remainder_100;

    int quotient_10 = 0;
    int remainder_10 = num;

    /*@
        loop invariant 0 <= quotient_10 <= ((((n) % 1000) % 100) / 10);
        loop invariant remainder_10 == (((n) % 1000) % 100) - quotient_10 * 10;
        loop invariant remainder_10 >= 0;
        loop assigns quotient_10, remainder_10;
        loop variant remainder_10;
    */
    while (remainder_10 >= 10)
    {
        quotient_10 += 1;
        remainder_10 -= 10;
    }

    sum += 10 * quotient_10;
    num = remainder_10;
    sum += num;

    //@ assert sum == (1000 * (((n)) / 1000) +         100 * ((((n)) % 1000) / 100) +         10 * (((((n)) % 1000) % 100) / 10) +         (((((n)) % 1000) % 100) % 10));
    return sum;
}

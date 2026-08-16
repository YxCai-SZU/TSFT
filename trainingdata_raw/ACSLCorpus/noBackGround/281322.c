#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    ensures \result == (a / 10 == (a / 100) * 10 || a % 10 == 5 || a == 100);
    ensures ((\result) == (((a) / 10 == ((a) / 100) * 10) || ((a) % 10 == 5) || ((a) == 100)));
*/
bool func(unsigned long long a)
{
    bool is_valid = false;
    unsigned long long temp = 0;
    unsigned long long quotient_100 = 0;
    unsigned long long remainder_100 = 0;
    unsigned long long product = 0;

    temp = a / 10;
    quotient_100 = 0;
    remainder_100 = a;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 0 <= quotient_100;
        loop invariant remainder_100 >= 0;
        loop invariant remainder_100 == a - quotient_100 * 100;
        loop assigns quotient_100, remainder_100;
        loop variant remainder_100;
    */
    while (remainder_100 >= 100)
    {
        remainder_100 -= 100;
        quotient_100 += 1;
    }

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 0 <= quotient_100;
        loop invariant remainder_100 < 100;
        loop invariant remainder_100 == a - quotient_100 * 100;
        loop assigns quotient_100, remainder_100;
        loop variant -remainder_100;
    */
    while (remainder_100 < 0)
    {
        remainder_100 += 100;
        quotient_100 -= 1;
    }

    product = quotient_100 * 10;

    //@ assert a / 100 == quotient_100;
    //@ assert product == (a / 100) * 10;

    if (temp == product || a % 10 == 5 || a == 100)
    {
        is_valid = true;
    }

    //@ assert ((is_valid) == (((a) / 10 == ((a) / 100) * 10) || ((a) % 10 == 5) || ((a) == 100)));
    return is_valid;
}

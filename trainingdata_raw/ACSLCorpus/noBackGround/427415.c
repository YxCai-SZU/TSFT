#include <limits.h>

/*@
    requires (0 <= (X) <= 1000000000);
    ensures \result == (((X) / 500) * 1000 + (((X) % 500) / 5) * 5);
*/
long long func(long long X)
{
    long long result = 0;
    long long temp = X;
    long long quotient_500 = 0;
    long long remainder_500 = temp;

    /*@
        loop invariant 0 <= quotient_500;
        loop invariant quotient_500 <= X / 500;
        loop invariant 0 <= remainder_500;
        loop invariant remainder_500 <= X;
        loop invariant remainder_500 == X - quotient_500 * 500;
        loop assigns quotient_500, remainder_500;
        loop variant remainder_500;
    */
    while (remainder_500 >= 500)
    {
        //@ assert remainder_500 >= 500;
        quotient_500 += 1;
        remainder_500 -= 500;
    }
    result += quotient_500 * 1000;
    temp = remainder_500;

    long long quotient_5 = 0;
    long long remainder_5 = temp;

    /*@
        loop invariant 0 <= quotient_5;
        loop invariant quotient_5 <= temp / 5;
        loop invariant 0 <= remainder_5;
        loop invariant remainder_5 <= temp;
        loop invariant remainder_5 == temp - quotient_5 * 5;
        loop assigns quotient_5, remainder_5;
        loop variant remainder_5;
    */
    while (remainder_5 >= 5)
    {
        //@ assert remainder_5 >= 5;
        quotient_5 += 1;
        remainder_5 -= 5;
    }
    result += quotient_5 * 5;

    //@ assert result == (((X) / 500) * 1000 + (((X) % 500) / 5) * 5);
    return result;
}

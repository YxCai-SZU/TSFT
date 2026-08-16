#include <stdbool.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == ( (a * b) % 2 != 0 );
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int product;
    int remainder;

    product = a * b;
    remainder = (int)product;

    /*@
        loop invariant 0 <= remainder <= product;
        loop invariant remainder % 2 == product % 2;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        remainder -= 2;
    }

    //@ assert remainder == product % 2;
    return remainder != 0;
}

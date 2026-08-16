#include <stdbool.h>

/*@
    requires a <= 100 && b <= 100 && c <= 100;
    ensures \result == (a * b / 2 <= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int product;
    unsigned int half_product;
    bool result;

    //@ assert ((a) <= 100 && (b) <= 100 ==> (a) * (b) <= 10000);
    product = a * b;
    half_product = product / 2;
    result = half_product <= c;
    return result;
}

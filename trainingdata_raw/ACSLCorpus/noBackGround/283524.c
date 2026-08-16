#include <stdbool.h>

/*@
    requires (0 <= (a) <= 10) && (0 <= (b) <= 10);
    ensures \result == (a * b >= 50);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int product;
    bool result;

    //@ assert 0 <= a && a <= 10;
    //@ assert 0 <= b && b <= 10;
    //@ assert a * b <= 100;

    product = a * b;
    //@ assert product == a * b;

    result = product >= 50;
    return result;
}

#include <stdbool.h>

/*@
    requires 1 <= x <= 10000;
    requires 1 <= y <= 10000;
    ensures \result == ((x * y) % 2 == 0);
*/
bool func(unsigned int x, unsigned int y)
{
    // Variable declarations at scope top
    unsigned int product;
    bool result;

    //@ assert (1 <= (x) <= 10000);
    //@ assert (1 <= (y) <= 10000);

    //@ assert ((x) * (y)) <= 100000000;
    product = x * y;

    //@ assert ((x) * (y)) == x * y;
    //@ assert product == ((x) * (y));

    result = (product % 2 == 0);
    //@ assert result == ((((x) * (y)) % 2) == 0);
    return result;
}

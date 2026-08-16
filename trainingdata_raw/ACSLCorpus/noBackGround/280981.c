#include <stdbool.h>

/*@
    requires 0 <= a <= 10000;
    requires 0 <= b <= 10000;
    requires 0 <= c <= 10000;
    ensures \result == (a * b < c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations
    unsigned int product;
    bool result;

    // Proof of equivalence
    //@ assert ((a) * (b) < (c)) ==> ((a) * (b) - (c) < 0);
    //@ assert ((a) * (b) - (c) < 0) ==> ((a) * (b) < (c));

    // Bound verification for multiplication
    //@ assert a * b <= 10000 * 10000;

    // Perform calculation
    product = a * b;
    result = product < c;

    // Final verification
    //@ assert result == (a * b < c);

    return result;
}

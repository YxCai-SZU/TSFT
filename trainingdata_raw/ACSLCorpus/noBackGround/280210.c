#include <stdbool.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == ((a * b) % 2 == 1);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b)
{
    // Variable declarations at top of scope
    unsigned long product;
    bool result;

    //@ assert 1 <= a && a <= 3;
    //@ assert 1 <= b && b <= 3;
    //@ assert a * b <= 9;

    product = a * b;
    result = (product % 2) == 1;
    return result;
}

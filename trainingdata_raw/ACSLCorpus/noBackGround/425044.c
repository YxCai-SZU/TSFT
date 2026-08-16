#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (((a) * (b)) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations
    unsigned int prod;
    bool result;

    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    //@ assert ((a) * (b)) <= 100000000;

    prod = a * b;

    if (prod % 2 == 0)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == (((a) * (b)) % 2 == 0);
    return result;
}

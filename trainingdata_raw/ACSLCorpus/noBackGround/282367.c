#include <stdbool.h>

/*@
    requires 1 <= a <= 5000;
    requires 1 <= b <= 5000;
    requires 1 <= c <= 10000;
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int diff;
    bool result;

    //@ assert a + b <= 10000;

    if (a + b >= c)
    {
        diff = a + b - c;
        //@ assert a + b >= c ==> diff == a + b - c;
    }
    else
    {
        diff = 0;
        //@ assert !(a + b >= c) ==> diff == 0;
    }

    result = (a + b >= c);
    return result;
}

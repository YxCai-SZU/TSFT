#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a % 2 == 0 || b % 2 == 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool a_even;
    bool b_even;
    bool result;

    a_even = (a % 2 == 0);
    b_even = (b % 2 == 0);

    if (a_even || b_even)
    {
        //@ assert a_even || b_even;
        result = true;
    }
    else
    {
        //@ assert !a_even && !b_even;
        result = false;
    }

    return result;
}

#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a % 2 == 0 || b % 2 == 0);
    ensures ((\result) == ((a) % 2 == 0 || (b) % 2 == 0));
*/
bool func(unsigned int a, unsigned int b)
{
    bool a_is_even;
    bool b_is_even;
    bool result;

    a_is_even = (a % 2 == 0);
    b_is_even = (b % 2 == 0);

    if (a_is_even)
    {
        //@ assert a_is_even == true;
        result = true;
    }
    else
    {
        //@ assert a_is_even == false;
        result = b_is_even;
    }

    //@ assert result == (a_is_even || b_is_even);
    //@ assert ((result) == ((a) % 2 == 0 || (b) % 2 == 0));
    return result;
}

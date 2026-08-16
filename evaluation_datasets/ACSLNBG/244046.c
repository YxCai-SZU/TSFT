#include <stdbool.h>


bool func(unsigned long a, unsigned long b)
{
    bool a_is_small;
    bool b_is_small;
    bool result;

    a_is_small = a <= 8;
    b_is_small = b <= 8;

    //@ assert a_is_small == (a <= 8);
    //@ assert b_is_small == (b <= 8);

    result = a_is_small && b_is_small;
    return result;
}

#include <stdbool.h>

/*@
    requires a <= 4294967295;
    requires b <= 4294967295;
    requires c <= 4294967295;
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool is_strictly_increasing = false;

    //@ assert a <= 4294967295 && b <= 4294967295 && c <= 4294967295;

    if (a < b)
    {
        if (b < c)
        {
            is_strictly_increasing = true;
        }
    }

    //@ assert is_strictly_increasing == (a < b && b < c);

    return is_strictly_increasing;
}

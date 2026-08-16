#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 16 &&
        1 <= (b) && (b) <= 16 &&
        (a) + (b) <= 16);
    ensures \result == true <==> ((a) <= 8 && (b) <= 8);
    assigns \nothing;
*/
bool input_tuple(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool result;

    if (a > 8 || b > 8)
    {
        //@ assert a > 8 || b > 8;
        result = false;
    }
    else
    {
        //@ assert a <= 8 && b <= 8;
        result = true;
    }

    return result;
}

#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == true <==> (((a) < (b) && (c) > (b)) || ((a) > (b) && (c) < (b)) || (a) == (b) || (b) == (c) || (a) == (c));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at the top
    bool result;

    if (a < b && c > b)
    {
        //@ assert a < b && c > b;
        result = true;
    }
    else if (a > b && c < b)
    {
        //@ assert a > b && c < b;
        result = true;
    }
    else if (a == b || b == c || a == c)
    {
        //@ assert a == b || b == c || a == c;
        result = true;
    }
    else
    {
        //@ assert !(((a) < (b) && (c) > (b)) || ((a) > (b) && (c) < (b)) || (a) == (b) || (b) == (c) || (a) == (c));
        result = false;
    }

    return result;
}

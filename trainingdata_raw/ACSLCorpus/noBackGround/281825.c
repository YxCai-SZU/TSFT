#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 9) && (1 <= (b) && (b) <= 9) && (1 <= (c) && (c) <= 9);
    ensures \result == true <==> (((a) == (b) && (a) != (c)) ||
        ((b) == (c) && (a) != (b)) ||
        ((c) == (a) && (b) != (c)));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;

    //@ assert (1 <= (a) && (a) <= 9) && (1 <= (b) && (b) <= 9) && (1 <= (c) && (c) <= 9);

    if ((a == b && b == c) || (a != b && b != c && c != a))
    {
        result = false;
    }
    else
    {
        //@ assert !((a == b && b == c) || (a != b && b != c && c != a));
        result = true;
    }

    //@ assert result == true <==> (((a) == (b) && (a) != (c)) ||         ((b) == (c) && (a) != (b)) ||         ((c) == (a) && (b) != (c)));
    return result;
}

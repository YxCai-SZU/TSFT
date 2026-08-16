#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9);
    requires (1 <= (b) <= 9);
    requires (1 <= (c) <= 9);
    ensures \result == true <==> (((a) == (b) + 1 && (b) == (c) + 1) ||
        ((a) == (b) - 1 && (b) == (c) - 1) ||
        ((a) == (b) + 2 && (b) == (c) + 1 && ((c) + 1) == (a) - 1) ||
        ((a) == (b) - 2 && (b) == (c) - 1 && ((c) - 1) == (a) + 1));
*/
bool func(int a, int b, int c)
{
    bool result;

    //@ assert b + 1 <= 10;
    
    if ((a == b + 1 && b == c + 1) ||
        (a == b - 1 && b == c - 1) ||
        (a == b + 2 && b == c + 1 && (c + 1) == a - 1) ||
        (a == b - 2 && b == c - 1 && (c - 1) == a + 1))
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

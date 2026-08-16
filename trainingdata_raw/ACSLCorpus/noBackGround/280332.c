#include <stdbool.h>
#include <stddef.h>

/*@
    requires (0 <= (a) <= 50);
    requires (0 <= (b) <= 50);
    requires (0 <= (c) <= 50);
    ensures \result >= 0;
    ensures \result <= 2;
    ensures \result == (((a) == (b) && (b) == (c)) ? 1 :
        ((a) == (b) || (b) == (c) || (a) == (c)) ? 2 : 0);
*/
size_t func(size_t a, size_t b, size_t c)
{
    size_t result;

    //@ assert a <= 50 && b <= 50 && c <= 50;

    if (a == b && b == c)
    {
        result = 1;
        //@ assert result == (((a) == (b) && (b) == (c)) ? 1 :         ((a) == (b) || (b) == (c) || (a) == (c)) ? 2 : 0);
    }
    else if (a == b || b == c || a == c)
    {
        result = 2;
        //@ assert result == (((a) == (b) && (b) == (c)) ? 1 :         ((a) == (b) || (b) == (c) || (a) == (c)) ? 2 : 0);
    }
    else
    {
        //@ assert a != b && b != c && a != c;
        result = 0;
        //@ assert result == (((a) == (b) && (b) == (c)) ? 1 :         ((a) == (b) || (b) == (c) || (a) == (c)) ? 2 : 0);
    }

    //@ assert result >= 0 && result <= 2;
    return result;
}

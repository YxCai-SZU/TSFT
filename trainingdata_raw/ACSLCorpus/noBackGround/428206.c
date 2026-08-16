#include <stdbool.h>
#include <stddef.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result <= 3;
    ensures \result == (((a) == (b) && (b) == (c)) ? 1 :
        ((a) == (b) && (b) != (c)) ? 2 :
        ((a) == (c) && (c) != (b)) ? 2 :
        ((b) == (c) && (c) != (a)) ? 2 :
        ((a) != (b) && (b) != (c) && (c) != (a)) ? 3 : 0);
*/
size_t func(size_t a, size_t b, size_t c)
{
    size_t result = 0;

    //@ assert result == 0;

    if (a == b && b == c)
    {
        result += 1;
        //@ assert result == 1;
    }

    if (a == b && b != c)
    {
        result += 2;
        //@ assert result == (((a) == (b) && (b) == (c)) ? 1 :         ((a) == (b) && (b) != (c)) ? 2 :         ((a) == (c) && (c) != (b)) ? 2 :         ((b) == (c) && (c) != (a)) ? 2 :         ((a) != (b) && (b) != (c) && (c) != (a)) ? 3 : 0);
    }

    if (a == c && c != b)
    {
        result += 2;
        //@ assert result == (((a) == (b) && (b) == (c)) ? 1 :         ((a) == (b) && (b) != (c)) ? 2 :         ((a) == (c) && (c) != (b)) ? 2 :         ((b) == (c) && (c) != (a)) ? 2 :         ((a) != (b) && (b) != (c) && (c) != (a)) ? 3 : 0);
    }

    if (b == c && c != a)
    {
        result += 2;
        //@ assert result == (((a) == (b) && (b) == (c)) ? 1 :         ((a) == (b) && (b) != (c)) ? 2 :         ((a) == (c) && (c) != (b)) ? 2 :         ((b) == (c) && (c) != (a)) ? 2 :         ((a) != (b) && (b) != (c) && (c) != (a)) ? 3 : 0);
    }

    if (a != b && b != c && c != a)
    {
        result += 3;
        //@ assert result == 3;
    }

    //@ assert result == (((a) == (b) && (b) == (c)) ? 1 :         ((a) == (b) && (b) != (c)) ? 2 :         ((a) == (c) && (c) != (b)) ? 2 :         ((b) == (c) && (c) != (a)) ? 2 :         ((a) != (b) && (b) != (c) && (c) != (a)) ? 3 : 0);
    //@ assert result >= 0 && result <= 3;

    return result;
}

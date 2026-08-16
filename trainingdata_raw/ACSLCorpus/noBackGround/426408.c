#include <stdbool.h>
#include <stddef.h>

/*@
    requires (0 <= (a) <= 100 &&
        2 <= (b) <= 1000 &&
        (b) % 2 == 0);
    ensures \result == ((a) < 13 ? 0 :
        (a) < 20 ? (b) / 2 :
        (b));
    ensures (a < 13 ==> \result == 0);
    ensures (a >= 13 && a < 20 ==> \result == b / 2);
    ensures (a >= 20 ==> \result == b);
*/
size_t func(size_t a, size_t b)
{
    size_t result;

    //@ assert (0 <= (a) <= 100 &&         2 <= (b) <= 1000 &&         (b) % 2 == 0);

    if (a < 13)
    {
        result = 0;
        //@ assert result == 0;
    }
    else if (a < 20)
    {
        result = b / 2;
        //@ assert result == b / 2;
    }
    else
    {
        result = b;
        //@ assert result == b;
    }

    //@ assert result == ((a) < 13 ? 0 :         (a) < 20 ? (b) / 2 :         (b));
    //@ assert (a < 13 ==> result == 0);
    //@ assert (a >= 13 && a < 20 ==> result == b / 2);
    //@ assert (a >= 20 ==> result == b);

    return result;
}

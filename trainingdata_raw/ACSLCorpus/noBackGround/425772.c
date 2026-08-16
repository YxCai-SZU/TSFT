#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 9 &&
        1 <= (b) && (b) <= 9 &&
        1 <= (c) && (c) <= 9);
    ensures \result >= 0 && \result <= 9;
    ensures (\result == 9) ==> (a != b && b != c && a != c);
    ensures (\result == 3) ==> (a == b && b == c);
    ensures (\result == 1 || \result == 2) ==> (a == b || b == c || a == c);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t result;

    //@ assert (1 <= (a) && (a) <= 9 &&         1 <= (b) && (b) <= 9 &&         1 <= (c) && (c) <= 9);

    if (a == b && b == c)
    {
        result = 3;
        //@ assert result == 3 && a == b && b == c;
    }
    else if (a != b && b != c && a != c)
    {
        result = 9;
        //@ assert result == 9 && a != b && b != c && a != c;
    }
    else
    {
        result = 1;
        //@ assert result == 1 && (a == b || b == c || a == c);
    }

    //@ assert result >= 0 && result <= 9;

    return result;
}

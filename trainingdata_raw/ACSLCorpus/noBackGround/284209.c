#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 9 &&
        1 <= (b) && (b) <= 9 &&
        1 <= (c) && (c) <= 9);
    ensures \result >= 1 && \result <= 3;
    ensures \result == (((a) == (b) && (b) == (c)) ? 3 :
        ((a) != (b) && (b) != (c) && (c) != (a)) ? 1 : 2);
*/
int func(long long a, long long b, long long c)
{
    int result;

    //@ assert (1 <= (a) && (a) <= 9 &&         1 <= (b) && (b) <= 9 &&         1 <= (c) && (c) <= 9);

    if (a == b && b == c)
    {
        //@ assert a == b && b == c;
        //@ assert a == c;
        result = 3;
    }
    else if (a != b && b != c && c != a)
    {
        //@ assert a != b && b != c && c != a;
        result = 1;
    }
    else
    {
        //@ assert a == b || b == c || c == a;
        //@ assert !(a == b && b == c);
        result = 2;
    }

    //@ assert result >= 1 && result <= 3;
    //@ assert result == (((a) == (b) && (b) == (c)) ? 3 :         ((a) != (b) && (b) != (c) && (c) != (a)) ? 1 : 2);
    return result;
}

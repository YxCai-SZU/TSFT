#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    ensures \result == (((a) == (b) && (b) == (c)) ? 1 :
        ((a) != (b) && (b) != (c) && (c) != (a)) ? 3 : 2);
*/
int func(int a, int b, int c)
{
    int result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);

    if (a == b && b == c)
    {
        result = 1;
        //@ assert result == (((a) == (b) && (b) == (c)) ? 1 :         ((a) != (b) && (b) != (c) && (c) != (a)) ? 3 : 2);
        return result;
    }
    else if (a != b && b != c && c != a)
    {
        result = 3;
        //@ assert result == (((a) == (b) && (b) == (c)) ? 1 :         ((a) != (b) && (b) != (c) && (c) != (a)) ? 3 : 2);
        return result;
    }
    else
    {
        //@ assert a == b || b == c || c == a;
        result = 2;
        //@ assert result == (((a) == (b) && (b) == (c)) ? 1 :         ((a) != (b) && (b) != (c) && (c) != (a)) ? 3 : 2);
        return result;
    }
}

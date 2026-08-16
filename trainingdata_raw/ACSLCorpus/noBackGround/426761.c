#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result <= a + b + c;
*/
int func(int a, int b, int c)
{
    int result = 0;

    //@ assert result == 0;

    if (c > a + b + 1)
    {
        //@ assert c - a - b - 1 >= 0;
        result += c - a - b - 1;
        //@ assert result >= 0;
    }

    if (b > a + c + 1)
    {
        //@ assert b - a - c - 1 >= 0;
        result += b - a - c - 1;
        //@ assert result >= 0;
    }

    if (a > b + c + 1)
    {
        //@ assert a - b - c - 1 >= 0;
        result += a - b - c - 1;
        //@ assert result >= 0;
    }

    //@ assert result >= 0;
    //@ assert result <= a + b + c;

    return result;
}

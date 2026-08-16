#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == -1 || (1 <= \result && \result <= 3) || \result == 10000;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;

    if (a == b && b == c)
    {
        result = 1;
        //@ assert result == 1;
        return result;
    }
    else if (a == b || a == c || b == c)
    {
        result = 2;
        //@ assert result == 2;
        return result;
    }
    else
    {
        result = 3;
        //@ assert result == 3;
        return result;
    }
}

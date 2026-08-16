#include <stdbool.h>

/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result == ((a) * 2) || \result == ((a) * 2 - 1) || \result == ((b) * 2 - 1);
*/
int func(int a, int b)
{
    int result;
    int min_val;

    result = 0;

    if (a == b)
    {
        result = a * 2;
        //@ assert result == ((a) * 2);
    }
    else
    {
        if (a < b)
        {
            min_val = a;
        }
        else
        {
            min_val = b;
        }
        result = min_val * 2 - 1;
        //@ assert result == ((min_val) * 2 - 1);
    }

    //@ assert result == ((a) * 2) || result == ((a) * 2 - 1) || result == ((b) * 2 - 1);
    return result;
}

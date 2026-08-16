#include <limits.h>

/*@
    requires (1 <= (a) <= 3 &&
        1 <= (b) <= 3 &&
        (a) != (b));
    ensures ((\result) == (6 - (((a)) + ((b)))) &&
        1 <= (\result) <= 3 &&
        (\result) != (a) &&
        (\result) != (b));
*/
int func(int a, int b)
{
    int sum;
    int result;

    sum = a + b;
    result = 0;

    if (sum == 3)
    {
        result = 3;
    }
    else if (sum == 5)
    {
        result = 1;
    }
    else if (sum == 4)
    {
        result = 2;
    }

    //@ assert result == 6 - (a + b);
    //@ assert 1 <= result <= 3;
    //@ assert result != a;
    //@ assert result != b;

    return result;
}

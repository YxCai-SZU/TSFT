#include <limits.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result <= 200;
*/
int func(int a, int b, int c)
{
    int max_val;
    int sum;
    int result;

    max_val = a;
    //@ assert max_val == a;

    if (b > max_val)
    {
        max_val = b;
    }
    //@ assert max_val >= a && max_val >= b;

    if (c > max_val)
    {
        max_val = c;
    }
    //@ assert max_val >= a && max_val >= b && max_val >= c;

    sum = a + b + c - max_val;
    //@ assert sum == a + b + c - max_val;

    if (sum < 0)
    {
        sum = -sum;
    }
    //@ assert sum >= 0;

    if (sum < max_val)
    {
        result = max_val - sum;
        //@ assert result == max_val - sum;
        return result;
    }
    else
    {
        result = 0;
        //@ assert result >= 0 && result <= 200;
        return result;
    }
}

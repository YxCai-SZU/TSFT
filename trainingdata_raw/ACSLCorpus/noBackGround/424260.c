#include <stdbool.h>

/*@
    requires (1 <= (a) <= 1000) && (1 <= (b) <= 1000) &&
             (1 <= (c) <= 1000) && (1 <= (d) <= 1000);
    ensures \result == a + c || \result == b + c ||
            \result == a + d || \result == b + d ||
            \result == a + c + d || \result == b + c + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int min_val;
    int max_val;
    int sum;
    int result;

    //@ assert (1 <= (a) <= 1000) && (1 <= (b) <= 1000);
    //@ assert (1 <= (c) <= 1000) && (1 <= (d) <= 1000);

    min_val = a < b ? a : b;
    max_val = a > b ? a : b;

    //@ assert min_val == ((a) < (b) ? (a) : (b));
    //@ assert max_val == ((a) > (b) ? (a) : (b));

    sum = 0;

    if (c > min_val)
    {
        sum = min_val + c;
    }
    else
    {
        sum = c + min_val;
    }

    //@ assert sum == min_val + c;

    if (d > sum)
    {
        sum = sum + d;
    }
    else
    {
        sum = d + sum;
    }

    //@ assert sum == min_val + c + d;

    if (a + c + d > sum)
    {
        result = a + c + d;
    }
    else
    {
        result = sum;
    }

    //@ assert result == a + c + d || result == min_val + c + d;

    if (b + c + d > result)
    {
        result = b + c + d;
    }

    //@ assert result == a + c + d || result == b + c + d || result == min_val + c + d;
    //@ assert result == a + c || result == b + c || result == a + d || result == b + d || result == a + c + d || result == b + c + d;

    return result;
}

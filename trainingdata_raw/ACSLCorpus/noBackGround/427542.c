#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 || \result == 2 || \result == 3;
*/
int func(int a, int b, int c)
{
    int min_val;
    int mid_val;
    int max_val;
    int temp;
    int result;
    int diff1;
    int diff2;

    min_val = a;
    mid_val = b;
    max_val = c;

    //@ assert (1 <= (min_val) && (min_val) <= 100) && (1 <= (mid_val) && (mid_val) <= 100) && (1 <= (max_val) && (max_val) <= 100);

    if (min_val > mid_val)
    {
        temp = min_val;
        min_val = mid_val;
        mid_val = temp;
    }
    //@ assert min_val <= mid_val;

    if (mid_val > max_val)
    {
        temp = mid_val;
        mid_val = max_val;
        max_val = temp;
    }
    //@ assert mid_val <= max_val;

    if (min_val > mid_val)
    {
        temp = min_val;
        min_val = mid_val;
        mid_val = temp;
    }
    //@ assert min_val <= mid_val && mid_val <= max_val;

    result = 0;
    diff1 = mid_val - min_val;
    diff2 = max_val - mid_val;

    //@ assert diff1 >= 0 && diff2 >= 0;

    if (diff1 == 0 && diff2 == 0)
    {
        result = 1;
    }
    else if ((diff1 == 0 && diff2 != 0) || (diff1 != 0 && diff2 == 0))
    {
        result = 2;
    }
    else
    {
        result = 3;
    }

    //@ assert result >= 1;
    //@ assert result <= 3;
    //@ assert result == 1 || result == 2 || result == 3;

    return result;
}

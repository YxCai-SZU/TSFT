#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int max_val;
    int min_val;
    int mid_val;
    int diff;
    int abs_diff;
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
    //@ assert max_val == (((a) >= (b) && (a) >= (c)) ? (a) : (((b) >= (c)) ? (b) : (c)));

    min_val = a;
    //@ assert min_val == a;
    if (b < min_val)
    {
        min_val = b;
    }
    //@ assert min_val <= a && min_val <= b;
    if (c < min_val)
    {
        min_val = c;
    }
    //@ assert min_val == (((a) <= (b) && (a) <= (c)) ? (a) : (((b) <= (c)) ? (b) : (c)));

    mid_val = a + b + c - max_val - min_val;
    //@ assert mid_val >= min_val && mid_val <= max_val;

    diff = max_val - (min_val * 2);
    //@ assert diff == max_val - 2 * min_val;

    if (diff < 0)
    {
        abs_diff = -diff;
    }
    else
    {
        abs_diff = diff;
    }
    //@ assert abs_diff == (((diff) >= 0) ? (diff) : -(diff));

    if (abs_diff <= mid_val)
    {
        result = 1;
    }
    else
    {
        if ((mid_val + min_val) == max_val)
        {
            result = 2;
        }
        else
        {
            result = 3;
        }
    }
    //@ assert result >= 1 && result <= 3;
    return result;
}

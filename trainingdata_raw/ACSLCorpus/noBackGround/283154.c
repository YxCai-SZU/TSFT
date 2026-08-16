#include <limits.h>

/*@
    requires (3 <= (a) <= 20) && (3 <= (b) <= 20);
    ensures \result == a + b || \result == b * 2 - 1 || \result == a * 2 - 1;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int min_val;
    int max_val;
    int diff;
    int min_sum_val;
    int max_sum_val;

    //@ assert (3 <= (a) <= 20) && (3 <= (b) <= 20);
    //@ assert a <= INT_MAX && b <= INT_MAX;

    if (a < b)
    {
        min_val = a;
    }
    else
    {
        min_val = b;
    }

    if (a > b)
    {
        max_val = a;
    }
    else
    {
        max_val = b;
    }

    //@ assert min_val == (((a) < (b)) ? (a) : (b));
    //@ assert max_val == (((a) > (b)) ? (a) : (b));

    diff = max_val - min_val;
    min_sum_val = min_val * 2 - 1;
    max_sum_val = max_val * 2 - 1;

    //@ assert min_sum_val == ((min_val) * 2 - 1);
    //@ assert max_sum_val == ((max_val) * 2 - 1);

    if (diff < min_sum_val)
    {
        diff = min_sum_val;
    }
    else
    {
        diff = max_sum_val;
    }

    //@ assert diff == ((((((a)) > ((b))) ? ((a)) : ((b))) - ((((a)) < ((b))) ? ((a)) : ((b))) < ((((((a)) < ((b))) ? ((a)) : ((b)))) * 2 - 1)) ?         ((((((a)) < ((b))) ? ((a)) : ((b)))) * 2 - 1) : ((((((a)) > ((b))) ? ((a)) : ((b)))) * 2 - 1));
    //@ assert diff == a * 2 - 1 || diff == b * 2 - 1;

    if (a + b < diff)
    {
        //@ assert a + b >= 0;
        return a + b;
    }
    else
    {
        //@ assert diff >= 0;
        return diff;
    }
}

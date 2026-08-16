#include <limits.h>

/*@
    requires (1 <= (a) <= 5000);
    requires (1 <= (b) <= 5000);
    requires (1 <= (c) <= 5000);
    requires (1 <= (d) <= 5000);
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
*/
int func(int a, int b, int c, int d)
{
    int diff1;
    int diff2;
    int min_val;
    int max_val;
    int result;

    //@ assert (1 <= (a) <= 5000) && (1 <= (b) <= 5000) && (1 <= (c) <= 5000) && (1 <= (d) <= 5000);

    diff1 = (a - b > 0) ? (a - b) : 0;
    //@ assert diff1 == (((a) > (b)) ? ((a) - (b)) : 0);
    //@ assert diff1 >= 0;

    diff2 = (c - d > 0) ? (c - d) : 0;
    //@ assert diff2 == (((c) > (d)) ? ((c) - (d)) : 0);
    //@ assert diff2 >= 0;

    min_val = (diff1 < diff2) ? diff1 : diff2;
    //@ assert min_val == (((diff1) < (diff2)) ? (diff1) : (diff2));
    //@ assert min_val >= 0;

    max_val = (diff1 > diff2) ? diff1 : diff2;
    //@ assert max_val == (((diff1) > (diff2)) ? (diff1) : (diff2));
    //@ assert max_val >= 0;

    if (min_val <= max_val)
    {
        //@ assert max_val - min_val >= 0;
        //@ assert max_val - min_val <= a + b + c + d;
        result = max_val - min_val;
    }
    else
    {
        result = 0;
    }

    //@ assert result >= 0;
    //@ assert result <= a + b + c + d;
    return result;
}

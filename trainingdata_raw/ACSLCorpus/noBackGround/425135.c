#include <stdbool.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (d) >= 0 && (e) >= 0 &&
        (a) < 124 && (b) < 124 && (c) < 124 && (d) < 124 && (e) < 124 &&
        (k) >= 0 && (k) < 124 &&
        (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == true <==> e - a <= k;
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int diff;
    int abs_diff;
    bool result;

    diff = e - a;
    
    //@ assert diff == e - a;
    
    if (diff < 0)
    {
        abs_diff = -diff;
    }
    else
    {
        abs_diff = diff;
    }
    
    //@ assert abs_diff >= 0;
    
    if (abs_diff <= k)
    {
        //@ assert e - a <= k;
        result = true;
    }
    else
    {
        //@ assert !(e - a <= k);
        result = false;
    }
    
    return result;
}

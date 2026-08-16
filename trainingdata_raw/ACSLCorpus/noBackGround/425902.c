#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d || \result == c + b;
    ensures \result <= 200;
*/
int func(int a, int b, int c, int d)
{
    int max_val;
    int temp_val;
    
    max_val = a + c;
    temp_val = a + d;
    
    //@ assert max_val == a + c || max_val == a + d;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }
    
    temp_val = b + c;
    //@ assert max_val == a + c || max_val == a + d || max_val == b + c;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }
    
    temp_val = b + d;
    //@ assert max_val == a + c || max_val == a + d || max_val == b + c || max_val == b + d;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }
    
    temp_val = c + b;
    //@ assert max_val == a + c || max_val == a + d || max_val == b + c || max_val == b + d || max_val == c + b;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }
    
    //@ assert max_val <= 200;
    return max_val;
}

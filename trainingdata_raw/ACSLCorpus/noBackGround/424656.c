#include <stdint.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == ((a) + (b)) || \result == ((a) - (b)) || \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) - (b));
    ensures \result >= ((a) * (b));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t x;
    int64_t y;
    int64_t z;
    int64_t max_val;
    
    x = a + b;
    y = a - b;
    
    //@ assert -10000 <= a * b <= 10000;
    
    z = a * b;
    
    if (x > y)
    {
        if (x > z)
        {
            max_val = x;
        }
        else
        {
            max_val = z;
        }
    }
    else
    {
        if (y > z)
        {
            max_val = y;
        }
        else
        {
            max_val = z;
        }
    }
    
    //@ assert max_val >= a + b;
    //@ assert max_val >= a - b;
    //@ assert max_val >= a * b;
    
    //@ assert max_val == ((a) + (b)) || max_val == ((a) - (b)) || max_val == ((a) * (b));
    
    return max_val;
}

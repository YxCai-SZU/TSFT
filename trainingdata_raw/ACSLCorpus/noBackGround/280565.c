#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == ((a) + (b)) || \result == ((a) - (b)) || \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) - (b));
    ensures \result >= ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int diff;
    int prod;
    int max_val;
    
    sum = a + b;
    diff = a - b;
    
    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    //@ assert -10000 <= a * b <= 10000;
    prod = a * b;
    
    if (sum > diff)
    {
        if (sum > prod)
        {
            max_val = sum;
        }
        else
        {
            max_val = prod;
        }
    }
    else
    {
        if (diff > prod)
        {
            max_val = diff;
        }
        else
        {
            max_val = prod;
        }
    }
    
    //@ assert max_val == sum || max_val == diff || max_val == prod;
    //@ assert max_val >= sum;
    //@ assert max_val >= diff;
    //@ assert max_val >= prod;
    //@ assert max_val >= ((a) + (b)) && max_val >= ((a) - (b)) && max_val >= ((a) * (b));
    
    return max_val;
}

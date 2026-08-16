#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == true <==> (a - b) <= (c - d);
    assigns \nothing;
*/
bool func(long long a, long long b, long long c, long long d)
{
    long long left;
    long long right;
    bool result;
    
    //@ assert -10000 <= a - b <= 10000;
    //@ assert -10000 <= c - d <= 10000;
    
    left = a - b;
    right = c - d;
    
    if (left <= right)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    return result;
}

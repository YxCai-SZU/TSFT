#include <limits.h>

/*@
    requires a > INT_MIN && b > INT_MIN && c > INT_MIN;
    requires a < INT_MAX && b < INT_MAX && c < INT_MAX;
    ensures \result == 1 <==> a < b && b < c;
*/
int func(int a, int b, int c)
{
    int result = 1;
    
    if (a >= b)
    {
        result = 0;
    }
    if (b >= c)
    {
        result = 0;
    }
    
    //@ assert result == 1 <==> a < b && b < c;
    
    return result;
}

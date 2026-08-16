#include <stdbool.h>

/*@
    requires 1 <= n <= 10000;
    requires 1 <= n1 <= 10000;
    ensures (\result == 0 && n + n1 < 10000) || (\result == 1 && n + n1 >= 10000);
*/
int func(int n, int n1)
{
    int sum;
    int result;
    
    sum = n + n1;
    
    if (sum >= 10000)
    {
        //@ assert sum >= 10000;
        result = 1;
    }
    else
    {
        //@ assert sum < 10000;
        result = 0;
    }
    
    return result;
}

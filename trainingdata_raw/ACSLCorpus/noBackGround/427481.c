#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == true <==> (((n) % 2 == 0 && (n) / 2 >= (k)) || ((n) % 2 == 1 && ((n) / 2 + 1) >= (k)));
*/
bool func(int n, int k)
{
    bool ret = false;
    
    //@ assert 1 <= n <= 100;
    //@ assert 1 <= k <= 100;
    
    if (n % 2 == 0)
    {
        if (n / 2 >= k)
        {
            ret = true;
        }
    }
    else
    {
        if ((n / 2 + 1) >= k)
        {
            ret = true;
        }
    }
    
    //@ assert ret == true <==> (((n) % 2 == 0 && (n) / 2 >= (k)) || ((n) % 2 == 1 && ((n) / 2 + 1) >= (k)));
    return ret;
}

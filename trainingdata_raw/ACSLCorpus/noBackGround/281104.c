#include <stdbool.h>

/*@
    requires 0 <= a < b < c < d < e <= 123;
    requires 0 <= k <= 123;
    ensures \result == (e - a <= k);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    bool ans = false;
    long diff = 0;

    diff = e - a;
    
    //@ assert diff == e - a;
    
    if (diff <= k)
    {
        ans = true;
    }
    
    //@ assert diff <= k ==> ans == true;
    //@ assert diff > k ==> ans == false;
    
    return ans;
}

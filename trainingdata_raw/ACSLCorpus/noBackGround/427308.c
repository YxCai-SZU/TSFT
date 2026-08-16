#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures (m >= n - 1 ==> \result == 1);
    ensures (m < n - 1 ==> \result == 0);
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t result;
    
    if (n == 1)
    {
        result = 1;
        //@ assert m >= n - 1 ==> result == 1;
        return result;
    }
    else if (m >= n - 1)
    {
        result = 1;
        //@ assert m >= n - 1 ==> result == 1;
        return result;
    }
    else
    {
        //@ assert m < n - 1;
        result = 0;
        //@ assert m < n - 1 ==> result == 0;
        return result;
    }
}

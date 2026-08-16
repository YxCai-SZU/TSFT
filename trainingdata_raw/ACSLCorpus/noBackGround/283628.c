#include <stdint.h>

/*@
    requires (0 <= (n) <= 100 && 0 <= (m) <= 100 && (m) != 0);
    ensures \result == ((m) + (n) >= 13 ? (n) : 13 - (m));
*/
int64_t func(int64_t n, int64_t m)
{
    int64_t result;
    //@ assert (0 <= (n) <= 100 && 0 <= (m) <= 100 && (m) != 0);
    
    if (m + n >= 13)
    {
        result = n;
    }
    else
    {
        result = 13 - m;
    }
    
    //@ assert result == ((m) + (n) >= 13 ? (n) : 13 - (m));
    return result;
}

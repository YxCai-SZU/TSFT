#include <stddef.h>

/*@
    requires (1 <= (k) && (k) <= 100 &&
        1 <= (n) && (n) <= 100000);
    ensures \result == 1 || \result == k - 1;
    ensures \result >= 1;
    ensures \result <= k - 1 + 1;
    assigns \nothing;
*/
size_t func(size_t k, size_t n)
{
    size_t result;
    
    //@ assert n % k == 0 || n % k != 0;
    
    if (n % k == 0)
    {
        result = 1;
        //@ assert result == 1;
    }
    else
    {
        result = k - 1;
        //@ assert result == k - 1;
    }
    
    return result;
}

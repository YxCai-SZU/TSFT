#include <stddef.h>

/*@
    requires (1 <= (n) <= 100000);
    ensures \result == ((n) / 2 + ((n) % 2));
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t res;
    
    res = n / 2;
    
    //@ assert res == n / 2;
    
    if (n % 2 == 1)
    {
        res += 1;
        //@ assert res == n / 2 + 1;
    }
    
    //@ assert res == n / 2 + (n % 2);
    
    return res;
}

#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result == (k * 500 >= x);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert ((k) * 500) == k * 500;
    
    result = (k * 500 >= x);
    
    //@ assert result == (((k) * 500) >= x);
    
    return result;
}

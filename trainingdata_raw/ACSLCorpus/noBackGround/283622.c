#include <stdbool.h>

/*@
    requires (1 <= (n) <= 10000) && (0 <= (a) <= 1000);
    ensures \result == (((n) % 500) <= a);
    assigns \nothing;
*/
bool func(unsigned long n, unsigned long a)
{
    // Variable declarations at top of scope
    unsigned long mod_val;
    bool result;

    //@ assert (1 <= (n) <= 10000);
    
    mod_val = n % 500;
    
    //@ assert mod_val == ((n) % 500);
    
    result = mod_val <= a;
    
    //@ assert result == (((n) % 500) <= a);
    
    return result;
}

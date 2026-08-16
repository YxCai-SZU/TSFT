#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result >= (800 * (n) - 200 * ((n) / 15));
    assigns \nothing;
*/
int func(size_t n)
{
    // Variable declarations at top of scope
    int x;
    int result;

    //@ assert (1 <= (n) && (n) <= 100);
    
    x = 800 * (int)n - 200 * ((int)n / 15);
    
    //@ assert x == (800 * (n) - 200 * ((n) / 15));
    //@ assert x + 1 >= (800 * (n) - 200 * ((n) / 15)) + 1;
    
    result = x + 1;
    
    //@ assert result >= (800 * (n) - 200 * ((n) / 15));
    return result;
}

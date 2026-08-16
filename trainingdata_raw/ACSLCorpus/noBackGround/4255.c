#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int result;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    //@ assert a * b <= 10000;
    
    result = a * b;
    
    //@ assert result == ((a) * (b));
    return result;
}

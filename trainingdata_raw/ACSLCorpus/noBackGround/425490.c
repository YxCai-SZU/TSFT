#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= 100 && 0 <= (b) <= 100);
    ensures \result == (a + b >= n);
    assigns \nothing;
*/
bool func(int n, int a, int b)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 0 <= a + b <= 200;
    
    if (a + b >= n)
    {
        //@ assert a + b >= n;
        result = true;
    }
    else
    {
        //@ assert a + b < n;
        result = false;
    }
    
    return result;
}

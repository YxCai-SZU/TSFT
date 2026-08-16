#include <stdbool.h>

/*@
    requires (2 <= (n) <= 100 &&
        1 <= (a) < (b) <= (n));
    ensures \result == ((((a) + (b)) % 2) == 0);
    assigns \nothing;
*/
bool func(int n, int a, int b)
{
    // Variable declarations at top of scope
    bool ret;
    int sum;
    int half;

    //@ assert (2 <= (n) <= 100 &&         1 <= (a) < (b) <= (n));
    
    sum = a + b;
    //@ assert sum <= 2 * n;
    
    half = sum / 2;
    //@ assert half <= n;
    
    if (sum % 2 == 0)
    {
        //@ assert (((a) + (b)) % 2) == 0;
        ret = true;
    }
    else
    {
        //@ assert (((a) + (b)) % 2) != 0;
        ret = false;
    }
    
    return ret;
}

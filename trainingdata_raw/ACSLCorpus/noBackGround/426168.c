#include <stdbool.h>

/*@
    requires 1 <= n && n <= 100;
    requires 1 <= m && m <= 100;
    ensures \result == true <==> (((n) % 2 == 0 && (m) % 2 == 1) || ((n) % 2 == 1 && (m) % 2 == 0));
 */
bool func(int n, int m)
{
    bool result;
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= 100;
    
    if ((n % 2 == 0 && m % 2 == 1) || (n % 2 == 1 && m % 2 == 0))
    {
        result = true;
        //@ assert (((n) % 2 == 0 && (m) % 2 == 1) || ((n) % 2 == 1 && (m) % 2 == 0));
    }
    else
    {
        result = false;
        //@ assert !(((n) % 2 == 0 && (m) % 2 == 1) || ((n) % 2 == 1 && (m) % 2 == 0));
    }
    
    return result;
}

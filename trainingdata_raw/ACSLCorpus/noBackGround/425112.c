#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (k) <= 100);
    ensures \result == true <==> (((n) + 1) / 2) >= k;
    assigns \nothing;
*/
bool func(int n, int k)
{
    // Variable declarations at scope top
    int x;
    bool result;
    
    //@ assert n < 2147483647;
    
    x = (n + 1) / 2;
    
    if (x >= k)
    {
        //@ assert x >= k;
        result = true;
    }
    else
    {
        //@ assert !(x >= k);
        result = false;
    }
    
    return result;
}

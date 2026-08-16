#include <stdbool.h>

/*@
    requires 1 <= n;
    requires 1 <= k;
    ensures \result == (n / 2 >= k - 1);
*/
bool func(int n, int k)
{
    bool result;
    
    //@ assert n / 2 >= k - 1 ==> n / 2 >= k - 1;
    
    if (n / 2 >= k - 1) {
        result = true;
    } else {
        //@ assert !(n / 2 >= k - 1);
        result = false;
    }
    
    return result;
}
